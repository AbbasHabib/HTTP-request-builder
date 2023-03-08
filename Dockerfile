# multi stage build 
# [0] builder image
FROM alpine:3.17.2 AS builder

COPY src/ /src/
COPY docker_build/ /docker_build/
RUN apk update
RUN apk add --no-cache g++=12.2.1_git20220924-r4
RUN apk add --no-cache cmake=3.24.3-r0
RUN apk add --no-cache make=4.3-r1
RUN apk add --no-cache curl-dev=7.88.1-r0
RUN (cd /docker_build; cmake .)
RUN (cd /docker_build ; make)

# [1] running image
FROM alpine:3.17.2

EXPOSE 443
EXPOSE 8443
RUN apk update
RUN apk add --no-cache curl=7.88.1-r0
RUN apk add --no-cache libstdc++=12.2.1_git20220924-r4
RUN rm -rf /var/cache/*
COPY --from=builder /docker_build/test_get_curl /
CMD [ "/test_get_curl" ]
