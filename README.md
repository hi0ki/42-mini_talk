# minitalk

This project implements a client-server communication system using signals.

## Description

minitalk allows a client to send a message to a server character by character, using only signals (SIGUSR1 and SIGUSR2). The server receives the message and displays it.

## Usage

1.  **Compile:**
    ```bash
    make
    ```
2.  **Run the server:**
    ```bash
    ./server
    ```
    The server will display its PID.
3.  **Run the client:**
    ```bash
    ./client <server_PID> "<message>"
    ```
    Replace `<server_PID>` with the server's PID and `<message>` with the message you want to send.

## Files

* `server.c`: The server program.
* `client.c`: The client program.
* `Makefile`: Compilation instructions.
