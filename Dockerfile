FROM devkitpro/devkitarm:20240906

# Install NFLib
# RUN cd libraries && git clone https://github.com/knightfox75/nds_nflib.git && mv nds_nflib nflib && ln -sT nflib /opt/devkitpro/nflib && cd nflib && make -f Makefile.dkp

RUN git clone https://github.com/knightfox75/nds_nflib.git && mv nds_nflib /opt/devkitpro/nflib && cd /opt/devkitpro/nflib && make -f Makefile.dkp

# Install nitro engine 
RUN git clone https://github.com/AntonioND/nitro-engine.git && mv nitro-engine /opt/devkitpro/nitro-engine && cd /opt/devkitpro/nitro-engine && make dkp -j`nproc`
