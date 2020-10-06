# Make DaVinci Resolve launch on Linux with AMDGPU-PRO OpenCL

This blacklists `clGetGLContextInfoKHR` extension which misbehaves when using AMDGPU-PRO OpenCL, without the rest of the proprietary component.

To use, build it and `LD_PRELOAD` the generated library.

### Building

```
make
```

### Usage

```
LD_PRELOAD=amdocl_fix.so /opt/resolve/bin/resolve
```

Or:

```
./run_resolve.sh
```
