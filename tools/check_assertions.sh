#!/bin/bash

ME=$(basename $0)
DIR="$(dirname $0)"

what=$1
shift
if [ "$what" = "warnings" ]; then
    grep -E "warning: Assertion" $*| sed "s/got status unknown/unproven/g"
else
    grep -E "warning: Assertion" $*|wc -l
fi