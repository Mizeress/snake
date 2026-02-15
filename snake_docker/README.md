# Snake Docker
## User Instructions

Run with docker run -it --device /dev/snd -v /run/user/$(id -u)/pipewire-0:/tmp/pipewire-0 -e PIPEWIRE_RUNTIME_DIR=/tmp -e XDG_RUNTIME_DIR=/tmp --group-add $(getent group audio | cut -d: -f3) <imagename>
`-it` grants an interactive terminal
`--device` /dev/snd grants the container access to your hosts sound cards
`-v /run/user/$(id -u)/pipewire-0:/tmp/pipewire-0` Mounts your host's PipeWire socekt into the container
`-e PIPEWIRE_RUNTIME_DIR=/tmp` Sets an environment variable to tell PipeWire to look for the socket in /tmp
`-e XDG_RUNTIME_DIR=/tmp` Sets standard Linux runtime directory to /tmp to ensure it uses that directory to store runtime files such as sockets
`--group-add $(getent group audio | cut -d: -f3)` Adds the container to the host's audio group to ensure it has proper permissions
If a container already exists, `docker start -i <container_name>`

## Troubleshooting

- Check Docker Logs and read messages

- Ensure libraries are installed

- Poke around in an interactive terminal

- Audio Problems?

- Check logs - if you see something like an ALSA message of ALSA being unable to open slave - it likely means the audio device it's trying to access is busy. Often this is because your host is already running an Audio Socket software like Pulse Audio or Pipewire. My system was using PipeWire, so the documentation and image here use that. If your system is not using pipewire, you will have to make some changes.
- Try a direct audio test:
  - `aplay -l` should list sound cards, if there aren't any sound cards listed, it means --device /dev/snd flag or permissions failed
  - `speaker-test -t pink -c 2` should play a sound. If so, then PipeWire is properly connected and it's likely a problem with the snake binary and/or audio resources is /usr/share/snake
  - `pactl info` If this fails, or doesn't show PipeWire, the socket or environment variables are off.
