FROM alpine:latest

RUN apk add --no-cache gcc musl-dev

COPY . /app
WORKDIR /app

RUN gcc -o calculator calculator.c -lm

CMD ["./calculator"]
