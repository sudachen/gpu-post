#ifndef __OCL_H__
#define __OCL_H__

#include <stdbool.h>

#ifndef CL_USE_DEPRECATED_OPENCL_1_0_APIS
#define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#endif

#ifndef CL_USE_DEPRECATED_OPENCL_1_1_APIS
#define CL_USE_DEPRECATED_OPENCL_1_1_APIS
#endif

#ifndef CL_USE_DEPRECATED_OPENCL_1_2_APIS
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#endif

#ifdef __APPLE_CC__
#include <OpenCL/opencl.h>
#else
#include "CL/cl.h"
#include "CL/cl_ext.h"
#endif

typedef struct {
	cl_context context;
	cl_kernel kernel[9];
	cl_command_queue commandQueue;
	cl_program program;

	cl_mem outputBuffer[2];
	cl_event outputEvent[2];

	cl_mem CLbuffer0;
	cl_mem padbuffer8;
	size_t padbufsize;

	bool hasBitAlign;
	bool hasOpenCL11plus;
	bool hasOpenCL12plus;
	size_t max_work_size;
	size_t wsize;
	size_t compute_shaders;
} _clState;

extern char *file_contents(const char *filename, int *length);
extern _clState *initCl(struct cgpu_info *cgpu, char *name, size_t nameSize, cl_uint hash_len_bits, bool throttled);

#endif /* __OCL_H__ */
