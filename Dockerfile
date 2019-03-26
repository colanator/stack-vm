FROM gcc:latest
COPY . /usr/src/stack-vm
WORKDIR /usr/src/stack-vm
RUN gcc -o stack-vm main.c
CMD ["./stack-vm", "Hello, World!"]