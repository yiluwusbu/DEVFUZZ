#!/bin/bash

echo "Enable Tracing"
echo 1 | sudo tee /sys/kernel/tracing/events/kvm/kvm_hypercall/enable
sudo cat /sys/kernel/debug/tracing/trace_pipe > kvm-trace.log

