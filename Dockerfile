FROM gcc:latest
COPY . /usr/src/stack-vm
WORKDIR /usr/src/stack-vm
RUN gcc -g -Wall -Wextra -pedantic main.c -o stack-vm
CMD ["./stack-vm", "demo.txt", "0", "20"]