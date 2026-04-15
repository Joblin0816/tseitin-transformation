FROM gcc:13

RUN apt-get update && apt-get install -y \
    cmake \
    make \
    default-jre \
    git \
    wget \
    locales \
    && locale-gen en_US.UTF-8 \
    && rm -rf /var/lib/apt/lists/*

ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8
ENV JAVA_TOOL_OPTIONS="-Dfile.encoding=UTF-8"
ENV LD_LIBRARY_PATH=/usr/local/lib

RUN git clone https://github.com/antlr/antlr4.git && \
    cd antlr4 && \
    git checkout 4.13.2 && \
    cd runtime/Cpp && \
    mkdir build && cd build && \
    cmake .. && make -j$(nproc) && make install

RUN wget https://www.antlr.org/download/antlr-4.13.2-complete.jar

WORKDIR /app

COPY . .

RUN rm -rf generated/* && \
    java -jar /antlr-4.13.2-complete.jar \
    -Dlanguage=Cpp \
    -visitor \
    -o generated \
    -Xexact-output-dir \
    grammar/Logic.g4

RUN mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

EXPOSE 18080

CMD ["./build/crow-server"]