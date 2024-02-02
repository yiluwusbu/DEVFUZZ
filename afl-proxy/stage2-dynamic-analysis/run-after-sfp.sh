#!/bin/bash

echo "Disable Tracing"
echo 0 | sudo tee /sys/kernel/tracing/events/kvm/kvm_hypercall/enable

