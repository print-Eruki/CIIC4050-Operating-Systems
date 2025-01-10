cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Set the project name
project(exercise4)


# Add the executable
add_executable(reader
 src/reader.c
)

add_executable(writer
 src/writer.c
)

add_executable(message_sender
 src/message_sender.c
)

add_executable(message_receiver
 src/message_receiver.c
)

