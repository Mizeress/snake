FROM ubuntu:latest

RUN apt update && apt install -y libncurses-dev alsa-utils pipewire-audio-client-libraries

COPY snake /usr/bin/
RUN chmod +x /usr/bin/snake

RUN mkdir /usr/share/snake
COPY *.wav /usr/share/snake
RUN chmod a+x /usr/share/snake/*.wav

CMD ["snake"]

