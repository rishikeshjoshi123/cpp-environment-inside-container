# Use the latest Ubuntu base image
FROM ubuntu:latest

# Install essential packages and C++ compiler
RUN apt-get update && apt-get install -y build-essential

# Set the working directory
WORKDIR /app

# Copy the source code into the container
COPY main.cpp .


# Set the entry point to a bash shell
CMD ["/bin/bash"]