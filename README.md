## Run Test App

cFS and this test app only run on a Linux OS, this repo provides a dockerfile that clones the cFS repo, adds test app, and finally builds an executable. 

To build the docker image:
```
docker build .
```

After docker build finishes, run these commands to run cFS and the test app
```
docker run -it --privileged DOCKER_IMAGE_ID
```

Then within the running image
```
echo 200 > /proc/sys/fs/mqueue/msg_max  # without this cFS fails to start

cd /cFS/build/exe/cpu1  # cFS probably uses relevant paths somewhere
./core-cpu1
```
# app-cfs-test
