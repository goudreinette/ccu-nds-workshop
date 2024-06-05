FROM devkitpro/devkitarm:latest
# Install the xz-utils package

# RUN wget https://apt.devkitpro.org/install-devkitpro-pacman
# RUN chmod +x ./install-devkitpro-pacman
# RUN ./install-devkitpro-pacman

# ensure apt is set up to work with https sources
RUN apt-get install -y apt-transport-https

# Store devkitPro gpg key locally if we don't have it already
RUN mkdir -p /usr/local/share/keyring/
RUN wget -O /usr/local/share/keyring/devkitpro-pub.gpg https://apt.devkitpro.org/devkitpro-pub.gpg

# Add the devkitPro apt repository if we don't have it set up already
RUN  echo "deb [signed-by=/usr/local/share/keyring/devkitpro-pub.gpg] https://apt.devkitpro.org stable main" > /etc/apt/sources.list.d/devkitpro.list

# Finally install devkitPro pacman
RUN apt-get update
RUN apt-get install -y devkitpro-pacman


RUN dkp-pacman -S --needed --noconfirm nds-dev  


ENV DEVKITPPC=${DEVKITPRO}/devkitPPC
ENV DEVKITARM=/opt/devkitpro/devkitARM