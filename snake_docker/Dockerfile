FROM ubuntu:latest

RUN apt update
RUN apt install -y libncurses-dev

COPY snake /usr/bin/
RUN chmod +x /usr/bin/snake

CMD ["snake"]

