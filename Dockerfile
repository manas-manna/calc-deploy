# Use Alpine Linux (lightweight OS)
FROM alpine:latest

# Install GCC compiler
RUN apk add --no-cache gcc musl-dev

# Copy your C program into the container
COPY calculator.c /app/calculator.c
WORKDIR /app

# Compile the C program
RUN gcc -o calculator calculator.c -lm

# Run the calculator
CMD ["./calculator"]

