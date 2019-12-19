#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/pirate/GitKracked/ws_FinalPirateRover/src/piraterover"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/pirate/GitKracked/ws_FinalPirateRover/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/pirate/GitKracked/ws_FinalPirateRover/install/lib/python2.7/dist-packages:/home/pirate/GitKracked/ws_FinalPirateRover/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pirate/GitKracked/ws_FinalPirateRover/build" \
    "/usr/bin/python" \
    "/home/pirate/GitKracked/ws_FinalPirateRover/src/piraterover/setup.py" \
    build --build-base "/home/pirate/GitKracked/ws_FinalPirateRover/build/piraterover" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/pirate/GitKracked/ws_FinalPirateRover/install" --install-scripts="/home/pirate/GitKracked/ws_FinalPirateRover/install/bin"
