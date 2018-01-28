#!/bin/sh

# Enforce current (vendor) directory
cd "${0%/*}"

URLS=(
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/guiddef.h"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/basetsd.h"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/windef.h"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/winnt.rh"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/winnt.h"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/pshpack2.h"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/pshpack4.h"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/pshpack8.h"
    "https://source.winehq.org/git/wine.git/blob_plain/HEAD:/include/poppack.h"
)

for URL in "${URLS[@]}"
do
    curl \
        --remote-name \
        --fail \
        --silent \
        --show-error \
        "$URL" &
done

wait

