STEP 1: image build command : docker build -t cpp-dev-env .
    -> this command builds the docker image based on the current dockerfile
    
STEP 2: container run command: docker run -it --rm -v "${PWD}/main.cpp:/app/main.cpp" cpp-dev-env
    -> this command runs the container and we'll compile the cpp file inside the container and execute there only...
    -> this command mounts the main.cpp file of the current directory to the main.cpp file inside the conatiner (-v "${PWD}/main.cpp:/app/main.cpp").
STEP 3: When the container starts, you'll see a bash terminal. Run the following two command there 
    -> g++ -o app main.cpp
    -> ./app
    OR you can run in a single command also 
        -> g++ -o app main.cpp && ./app
