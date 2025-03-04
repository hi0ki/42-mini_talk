# minitalk

This project implements a client-server communication system using signals.

## Description

minitalk allows a client to send a message to a server character by character, using only signals (SIGUSR1 and SIGUSR2). The server receives these signals, reconstructs the message, and displays it. This project allowed me to learn and demonstrate proficiency in:
* Signal handling,
* Bitwise operations,
* Low-level communication,
* Binary data conversion,
* And the fundamentals of client-server architecture.

## Usage

1.  **Compile:**
    ```bash
    make
    ```
    This will compile both the `server` and `client` executables.
2.  **Run the server:**
    ```bash
    ./server
    ```
    The server will start listening for signals and display its process ID (PID). This PID is required for the client to know where to send the signals.
3.  **Run the client:**
    ```bash
    ./client <server_PID> "<message>"
    ```
    Replace `<server_PID>` with the server's PID and `<message>` with the message you want to send. The client will send each bit of the message's characters as a sequence of `SIGUSR1` and `SIGUSR2` signals.

## Detailed Explanation

* **Signal Encoding:** Each character is broken down into its binary representation. `SIGUSR1` represents a `0`, and `SIGUSR2` represents a `1`. These signals are sent bit by bit to the server.
* **Server Reception:** The server receives the signals and reconstructs the binary representation of each character. It then converts the binary back into ASCII and displays the complete message.
* **Error Handling:** Basic error handling is implemented to ensure the server and client can handle invalid input or unexpected signal sequences.

