# multistage build

# [0] builder image
FROM ubuntu:18.04 AS builder
RUN apt-get update -y
RUN apt-get install g++ -y
RUN apt-get install cmake -y
RUN apt-get install make -y
RUN apt-get install curl -y
RUN apt-get install -y libcurl4-openssl-dev 
COPY src/ /src/
COPY docker_build/ /docker_build/
RUN ls 
RUN ls docker_build
RUN ls src
RUN ls /usr/lib/x86_64-linux-gnu/
RUN (cd /docker_build; cmake .)
RUN (cd /docker_build ; make)
RUN ls docker_build


# [1] running image
FROM ubuntu:18.04
RUN apt-get update -y
RUN apt-get install -y libcurl4-openssl-dev 
COPY --from=builder /docker_build/test_get_curl /
CMD [ "/test_get_curl" ]
