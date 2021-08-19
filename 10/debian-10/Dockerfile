FROM docker.io/radondb/minideb:buster
LABEL maintainer "radondb"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN echo "deb http://mirrors.aliyun.com/debian/ buster main" > /etc/apt/sources.list
COPY prebuildfs /
# Install required system packages and dependencies
RUN install_packages curl procps

ENV QINGCLOUD_APP_NAME="qingcloud-shell" \
    QINGCLOUD_IMAGE_VERSION="10-debian-10-r166" \
    OS_ARCH="amd64" \
    OS_FLAVOUR="debian-10" \
    OS_NAME="linux"

