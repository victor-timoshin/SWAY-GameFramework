#ifndef WRAPFUNC_H
#define WRAPFUNC_H

#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	bool IsExtensionSupported(const char* extensions, const char* name);
	void InitializeExtensions(void);

	// GL_ARB_vertex_buffer_objectglDeleteVertexArrays
	extern PFNGLBINDBUFFERARBPROC glBindBufferARB;
	extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;
	extern PFNGLGENBUFFERSARBPROC glGenBuffersARB;
	extern PFNGLISBUFFERARBPROC glIsBufferARB;
	extern PFNGLBUFFERDATAARBPROC glBufferDataARB;
	extern PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
	extern PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubDataARB;
	extern PFNGLMAPBUFFERARBPROC glMapBufferARB;
	extern PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
	extern PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB;
	extern PFNGLGETBUFFERPOINTERVARBPROC glGetBufferPointervARB;

	// GL_ARB_map_buffer_range
	extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange;

	// GL_ARB_vertex_array_object
	extern PFNGLBINDVERTEXARRAYPROC glBindVertexArrayARB;
	extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArraysARB;
	extern PFNGLGENVERTEXARRAYSPROC glGenVertexArraysARB;
	extern PFNGLISVERTEXARRAYPROC glIsVertexArrayARB;

	// GL_ARB_shader_objects
	extern PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
	extern PFNGLGETHANDLEARBPROC glGetHandleARB;
	extern PFNGLDETACHOBJECTARBPROC glDetachObjectARB;
	extern PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
	extern PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
	extern PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
	extern PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
	extern PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
	extern PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
	extern PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
	extern PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB;
	extern PFNGLUNIFORM1FARBPROC glUniform1fARB;
	extern PFNGLUNIFORM2FARBPROC glUniform2fARB;
	extern PFNGLUNIFORM3FARBPROC glUniform3fARB;
	extern PFNGLUNIFORM4FARBPROC glUniform4fARB;
	extern PFNGLUNIFORM1IARBPROC glUniform1iARB;
	extern PFNGLUNIFORM2IARBPROC glUniform2iARB;
	extern PFNGLUNIFORM3IARBPROC glUniform3iARB;
	extern PFNGLUNIFORM4IARBPROC glUniform4iARB;
	extern PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fvARB;
	extern PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fvARB;
	extern PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB;
	extern PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfvARB;
	extern PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
	extern PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
	extern PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObjectsARB;
	extern PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
	extern PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniformARB;
	extern PFNGLGETUNIFORMFVARBPROC glGetUniformfvARB;
	extern PFNGLGETUNIFORMIVARBPROC glGetUniformivARB;
	extern PFNGLGETSHADERSOURCEARBPROC glGetShaderSourceARB;

	// GL_ARB_vertex_program
	extern PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARB;
	extern PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARB;
	extern PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARB;
	extern PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARB;
	extern PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARB;
	extern PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARB;
	extern PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARB;
	extern PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARB;
	extern PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARB;
	extern PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARB;
	extern PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARB;
	extern PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARB;
	extern PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARB;
	extern PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARB;
	extern PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARB;
	extern PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARB;
	extern PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARB;
	extern PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARB;
	extern PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARB;
	extern PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARB;
	extern PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARB;
	extern PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARB;
	extern PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARB;
	extern PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARB;
	extern PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARB;
	extern PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARB;
	extern PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARB;
	extern PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARB;
	extern PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARB;
	extern PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARB;
	extern PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARB;
	extern PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARB;
	extern PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARB;
	extern PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARB;
	extern PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARB;
	extern PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARB;
	extern PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARB;
	extern PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARB;
	extern PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARB;
	extern PFNGLPROGRAMSTRINGARBPROC glProgramStringARB;
	extern PFNGLBINDPROGRAMARBPROC glBindProgramARB;
	extern PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB;
	extern PFNGLGENPROGRAMSARBPROC glGenProgramsARB;
	extern PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARB;
	extern PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARB;
	extern PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARB;
	extern PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARB;
	extern PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB;
	extern PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB;
	extern PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB;
	extern PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB;
	extern PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARB;
	extern PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARB;
	extern PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB;
	extern PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB;
	extern PFNGLGETPROGRAMIVARBPROC glGetProgramivARB;
	extern PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARB;
	extern PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARB;
	extern PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARB;
	extern PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARB;
	extern PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARB;
	extern PFNGLISPROGRAMARBPROC glIsProgramARB;

	// GL_ARB_vertex_shader
	extern PFNGLBINDATTRIBLOCATIONARBPROC glBindAttribLocationARB;
	extern PFNGLGETACTIVEATTRIBARBPROC glGetActiveAttribARB;
	extern PFNGLGETATTRIBLOCATIONARBPROC glGetAttribLocationARB;

	// GL_ARB_framebuffer_object
	extern PFNGLISRENDERBUFFERPROC glIsRenderbufferARB;
	extern PFNGLBINDRENDERBUFFERPROC glBindRenderbufferARB;
	extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffersARB;
	extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffersARB;
	extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorageARB;
	extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameterivARB;
	extern PFNGLISFRAMEBUFFERPROC glIsFramebufferARB;
	extern PFNGLBINDFRAMEBUFFERPROC glBindFramebufferARB;
	extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffersARB;
	extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffersARB;
	extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatusARB;
	extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1DARB;
	extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2DARB;
	extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3DARB;
	extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbufferARB;
	extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameterivARB;
	extern PFNGLGENERATEMIPMAPPROC glGenerateMipmapARB;
	extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebufferARB;
	extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisampleARB;
	extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayerARB;

	// GL_ARB_multitexture
	extern PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
	extern PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB;
	extern PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB;
	extern PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB;
	extern PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB;
	extern PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB;
	extern PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB;
	extern PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB;
	extern PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB;
	extern PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB;
	extern PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB;
	extern PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB;
	extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
	extern PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB;
	extern PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB;
	extern PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB;
	extern PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB;
	extern PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB;
	extern PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB;
	extern PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB;
	extern PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB;
	extern PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB;
	extern PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB;
	extern PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB;
	extern PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB;
	extern PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB;
	extern PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB;
	extern PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB;
	extern PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB;
	extern PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB;
	extern PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB;
	extern PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB;
	extern PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB;
	extern PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB;

	// GL_ARB_texture_compression
	extern PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB;
	extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB;
	extern PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB;
	extern PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB;

	// GL_ARB_sampler_objects
	extern PFNGLGENSAMPLERSPROC glGenSamplersARB;
	extern PFNGLDELETESAMPLERSPROC glDeleteSamplersARB;
	extern PFNGLISSAMPLERPROC glIsSamplerARB;
	extern PFNGLBINDSAMPLERPROC glBindSamplerARB;
	extern PFNGLSAMPLERPARAMETERIPROC glSamplerParameteriARB;
	extern PFNGLSAMPLERPARAMETERIVPROC glSamplerParameterivARB;
	extern PFNGLSAMPLERPARAMETERFPROC glSamplerParameterfARB;
	extern PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfvARB;
	extern PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIivARB;
	extern PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuivARB;
	extern PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameterivARB;
	extern PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIivARB;
	extern PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfvARB;
	extern PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuivARB;

	namespace GL_ARB_VertexBufferObject
	{
		void BindBuffer(UInt target, UInt buffer, const char* breakpointLocation);

		void UnbindBuffer(UInt target, const char* breakpointLocation);

		void DeleteBuffers(UInt num, UInt* buffers);

		void GenerateBuffers(UInt num, UInt* buffers, const char* breakpointLocation);

		bool IsBuffer(UInt buffer);

		void BufferData(UInt target, UInt size, const void* data, UInt usage, const char* breakpointLocation);

		void BufferSubData(UInt target, UInt offset, UInt size, const void* data, const char* breakpointLocation);

		void GetBufferSubData(UInt target, int offset, int size, void* data, const char* breakpointLocation);

		void* MapBuffer(UInt target, UInt access, const char* breakpointLocation);

		void UnmapBuffer(UInt target, const char* breakpointLocation);

		void GetBufferParameterI(UInt target, UInt value, int* params, const char* breakpointLocation);

		void GetBufferPointer(UInt target, UInt value, void** params, const char* breakpointLocation);
	}

	namespace GL_ARB_MapBufferRange
	{
		void* MapBufferRange(UInt target, int offset, int length, UInt access, const char* breakpointLocation);
	}

	namespace GL_ARB_VertexArrayObject
	{
		void BindVertexArray(UInt array, const char* breakpointLocation);

		void UnbindVertexArray(const char* breakpointLocation);

		void DeleteVertexArrays(int num, UInt* arrays);

		void GenerateVertexArrays(UInt num, UInt* arrays, const char* breakpointLocation);

		bool IsVertexArray(UInt array);
	}

	namespace GL_ARB_ShaderObjects
	{
		void DeleteObject(UInt obj);

		UInt GetHandle(UInt value);

		void DetachObject(UInt containerObj, UInt attachedObj, const char* breakpointLocation);

		UInt CreateShaderObject(UInt shaderType, const char* breakpointLocation);

		void ShaderSource(UInt objectID, int count, const char** source, const int* length, const char* breakpointLocation);

		void CompileShader(UInt objectID, const char* breakpointLocation);

		UInt CreateProgramObject(const char* breakpointLocation);

		void AttachObject(UInt containerObj, UInt obj, const char* breakpointLocation);

		void LinkProgram(UInt programObj, const char* breakpointLocation);

		void UseProgramObject(UInt programObj, const char* breakpointLocation);

		void ValidateProgram(UInt programObj, const char* breakpointLocation);

		void Uniform1F(int location, float value0, const char* breakpointLocation);

		void Uniform2F(int location, float value0, float value1, const char* breakpointLocation);

		void Uniform3F(int location, float value0, float value1, float value2, const char* breakpointLocation);

		void Uniform4F(int location, float value0, float value1, float value2, float value3, const char* breakpointLocation);

		void Uniform1I(int location, int value0, const char* breakpointLocation);

		void Uniform2I(int location, int value0, int value1, const char* breakpointLocation);

		void Uniform3I(int location, int value0, int value1, int value2, const char* breakpointLocation);

		void Uniform4I(int location, int value0, int value1, int value2, int value3, const char* breakpointLocation);

		void UniformMatrix2(int location, int count, bool transpose, const float* value, const char* breakpointLocation);

		void UniformMatrix3(int location, int count, bool transpose, const float* value, const char* breakpointLocation);

		void UniformMatrix4(int location, int count, bool transpose, const float* value, const char* breakpointLocation);

		void GetObjectParameterF(UInt obj, int value, float* params, const char* breakpointLocation);

		void GetObjectParameterI(UInt obj, int value, int* params, const char* breakpointLocation);

		void GetInfoLog(UInt obj, int maxLength, int* length, char* infoLog, const char* breakpointLocation);

		void GetAttachedObjects(UInt containerObj, int maxCount, int* count, UInt* obj, const char* breakpointLocation);

		int GetUniformLocation(UInt programObj, const char* name, const char* breakpointLocation);

		void GetActiveUniform(UInt programObj, UInt index, int maxLength, int* length, int* size, UInt* type, char* name, const char* breakpointLocation);

		void GetUniformF(UInt programObj, int location, float* params, const char* breakpointLocation);

		void GetUniformI(UInt programObj, int location, int* params, const char* breakpointLocation);

		void GetShaderSource(UInt obj, int maxLength, int* length, char* source, const char* breakpointLocation);
	}

	namespace GL_ARB_VertexProgram
	{
		void VertexAttributePointer(UInt index, int size, UInt type, bool normalized, int stride, const void* pointer, const char* breakpointLocation);

		void EnableVertexAttributeArray(UInt index, const char* breakpointLocation);

		void DisableVertexAttributeArray(UInt index, const char* breakpointLocation);

		void ProgramString(UInt target, UInt format, int length, const void* str, const char* breakpointLocation);

		void DeletePrograms(int num, const UInt* programs, const char* breakpointLocation);
	}

	namespace GL_ARB_VertexShader
	{
		void BindAttributeLocation(UInt programObj, int index, const char* name, const char* breakpointLocation);

		void GetActiveAttribute(UInt programObj, int index, int maxLength, int* length, int* size, UInt* type, char* name, const char* breakpointLocation);

		int GetAttributeLocation(UInt programObj, const char* name, const char* breakpointLocation);
	}

	namespace GL_ARB_FramebufferObject
	{
		bool IsRenderbuffer(UInt renderBuffer);

		void BindRenderbuffer(UInt target, UInt renderBuffer, const char* breakpointLocation);

		void DeleteRenderbuffers(int num, UInt* renderBuffers);

		void GenRenderbuffers(int num, UInt* renderBuffers, const char* breakpointLocation);

		void RenderbufferStorage(UInt target, UInt internalFormat, int width, int height, const char* breakpointLocation);

		bool IsFramebuffer(UInt framebuffer);

		void BindFramebuffer(UInt target, UInt frameBuffer, const char* breakpointLocation);

		void DeleteFramebuffers(int num, UInt* frameBuffers);

		void GenFramebuffers(int num, UInt* frameBuffers, const char* breakpointLocation);

		bool CheckFramebufferStatus(UInt target, const char* breakpointLocation);

		void FramebufferTexture2D(UInt target, UInt attachment, UInt texureTarget, UInt texture, int level, const char* breakpointLocation);
		
		void FramebufferRenderbuffer(UInt target, UInt attachment, UInt renderBufferTarget, UInt renderBuffer, const char* breakpointLocation);
		
		void GenerateMipmap(UInt target, const char* breakpointLocation);
	}

	namespace GL_ARB_Multitexture
	{
		void ActiveTexture(UInt texture, const char* breakpointLocation);

		void ClientActiveTexture(UInt texture, const char* breakpointLocation);
	}

	namespace GL_ARB_TextureCompression
	{
	}

	namespace GL_ARB_SamplerObjects
	{
		void GenSamplers(int count, UInt* samplers, const char* breakpointLocation);

		void SamplerParameterI(UInt sampler, UInt value, int param, const char* breakpointLocation);
	}
}

#endif // WRAPFUNC_H