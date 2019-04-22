FROM gcc:latest
COPY . /usr/src/stack-vm
WORKDIR /usr/src/stack-vm
RUN gcc -o stack-vm main.c
CMD ["./stack-vm", "test.txt", "3", "5"]