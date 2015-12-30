#include "../../GapiOpenGL/Inc/WrapFunc.h"

namespace Gapi
{
	// GL_ARB_vertex_buffer_object
	PFNGLBINDBUFFERARBPROC glBindBufferARB = nullptr;
	PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = nullptr;
	PFNGLGENBUFFERSARBPROC glGenBuffersARB = nullptr;
	PFNGLISBUFFERARBPROC glIsBufferARB = nullptr;
	PFNGLBUFFERDATAARBPROC glBufferDataARB = nullptr;
	PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB = nullptr;
	PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubDataARB = nullptr;
	PFNGLMAPBUFFERARBPROC glMapBufferARB = nullptr;
	PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB = nullptr;
	PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB = nullptr;
	PFNGLGETBUFFERPOINTERVARBPROC glGetBufferPointervARB = nullptr;

	// GL_ARB_map_buffer_range
	PFNGLMAPBUFFERRANGEPROC glMapBufferRange = nullptr;

	// GL_ARB_vertex_array_object
	PFNGLBINDVERTEXARRAYPROC glBindVertexArrayARB = nullptr;
	PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArraysARB = nullptr;
	PFNGLGENVERTEXARRAYSPROC glGenVertexArraysARB = nullptr;
	PFNGLISVERTEXARRAYPROC glIsVertexArrayARB = nullptr;

	// GL_ARB_shader_objects
	PFNGLDELETEOBJECTARBPROC glDeleteObjectARB = nullptr;
	PFNGLGETHANDLEARBPROC glGetHandleARB = nullptr;
	PFNGLDETACHOBJECTARBPROC glDetachObjectARB = nullptr;
	PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB = nullptr;
	PFNGLSHADERSOURCEARBPROC glShaderSourceARB = nullptr;
	PFNGLCOMPILESHADERARBPROC glCompileShaderARB = nullptr;
	PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB = nullptr;
	PFNGLATTACHOBJECTARBPROC glAttachObjectARB = nullptr;
	PFNGLLINKPROGRAMARBPROC glLinkProgramARB = nullptr;
	PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB = nullptr;
	PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB = nullptr;
	PFNGLUNIFORM1FARBPROC glUniform1fARB = nullptr;
	PFNGLUNIFORM2FARBPROC glUniform2fARB = nullptr;
	PFNGLUNIFORM3FARBPROC glUniform3fARB = nullptr;
	PFNGLUNIFORM4FARBPROC glUniform4fARB = nullptr;
	PFNGLUNIFORM1IARBPROC glUniform1iARB = nullptr;
	PFNGLUNIFORM2IARBPROC glUniform2iARB = nullptr;
	PFNGLUNIFORM3IARBPROC glUniform3iARB = nullptr;
	PFNGLUNIFORM4IARBPROC glUniform4iARB = nullptr;
	PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fvARB = nullptr;
	PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fvARB = nullptr;
	PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB = nullptr;
	PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfvARB = nullptr;
	PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB = nullptr;
	PFNGLGETINFOLOGARBPROC glGetInfoLogARB = nullptr;
	PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObjectsARB = nullptr;
	PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB = nullptr;
	PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniformARB = nullptr;
	PFNGLGETUNIFORMFVARBPROC glGetUniformfvARB = nullptr;
	PFNGLGETUNIFORMIVARBPROC glGetUniformivARB = nullptr;
	PFNGLGETSHADERSOURCEARBPROC glGetShaderSourceARB = nullptr;

	// GL_ARB_vertex_program
	PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARB = nullptr;
	PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARB = nullptr;
	PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARB = nullptr;
	PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARB = nullptr;
	PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARB = nullptr;
	PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARB = nullptr;
	PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARB = nullptr;
	PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARB = nullptr;
	PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARB = nullptr;
	PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARB = nullptr;
	PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARB = nullptr;
	PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARB = nullptr;
	PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARB = nullptr;
	PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARB = nullptr;
	PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARB = nullptr;
	PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARB = nullptr;
	PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARB = nullptr;
	PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARB = nullptr;
	PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARB = nullptr;
	PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARB = nullptr;
	PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARB = nullptr;
	PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARB = nullptr;
	PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARB = nullptr;
	PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARB = nullptr;
	PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARB = nullptr;
	PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARB = nullptr;
	PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARB = nullptr;
	PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARB = nullptr;
	PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARB = nullptr;
	PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARB = nullptr;
	PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARB = nullptr;
	PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARB = nullptr;
	PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARB = nullptr;
	PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARB = nullptr;
	PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARB = nullptr;
	PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARB = nullptr;
	PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARB = nullptr;
	PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARB = nullptr;
	PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARB = nullptr;
	PFNGLPROGRAMSTRINGARBPROC glProgramStringARB = nullptr;
	PFNGLBINDPROGRAMARBPROC glBindProgramARB = nullptr;
	PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB = nullptr;
	PFNGLGENPROGRAMSARBPROC glGenProgramsARB = nullptr;
	PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARB = nullptr;
	PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARB = nullptr;
	PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARB = nullptr;
	PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARB = nullptr;
	PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB = nullptr;
	PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB = nullptr;
	PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB = nullptr;
	PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB = nullptr;
	PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARB = nullptr;
	PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARB = nullptr;
	PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB = nullptr;
	PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB = nullptr;
	PFNGLGETPROGRAMIVARBPROC glGetProgramivARB = nullptr;
	PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARB = nullptr;
	PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARB = nullptr;
	PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARB = nullptr;
	PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARB = nullptr;
	PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARB = nullptr;
	PFNGLISPROGRAMARBPROC glIsProgramARB = nullptr;

	// GL_ARB_vertex_shader
	PFNGLBINDATTRIBLOCATIONARBPROC glBindAttribLocationARB = nullptr;
	PFNGLGETACTIVEATTRIBARBPROC glGetActiveAttribARB = nullptr;
	PFNGLGETATTRIBLOCATIONARBPROC glGetAttribLocationARB = nullptr;

	// GL_ARB_framebuffer_object
	PFNGLISRENDERBUFFERPROC glIsRenderbufferARB = nullptr;
	PFNGLBINDRENDERBUFFERPROC glBindRenderbufferARB = nullptr;
	PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffersARB = nullptr;
	PFNGLGENRENDERBUFFERSPROC glGenRenderbuffersARB = nullptr;
	PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorageARB = nullptr;
	PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameterivARB = nullptr;
	PFNGLISFRAMEBUFFERPROC glIsFramebufferARB = nullptr;
	PFNGLBINDFRAMEBUFFERPROC glBindFramebufferARB = nullptr;
	PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffersARB = nullptr;
	PFNGLGENFRAMEBUFFERSPROC glGenFramebuffersARB = nullptr;
	PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatusARB = nullptr;
	PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1DARB = nullptr;
	PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2DARB = nullptr;
	PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3DARB = nullptr;
	PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbufferARB = nullptr;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameterivARB = nullptr;
	PFNGLGENERATEMIPMAPPROC glGenerateMipmapARB = nullptr;
	PFNGLBLITFRAMEBUFFERPROC glBlitFramebufferARB = nullptr;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisampleARB = nullptr;
	PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayerARB = nullptr;

	// GL_ARB_multitexture
	PFNGLACTIVETEXTUREARBPROC glActiveTextureARB = nullptr;
	PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB = nullptr;
	PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB = nullptr;
	PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB = nullptr;
	PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB = nullptr;
	PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB = nullptr;
	PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB = nullptr;
	PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB = nullptr;
	PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB = nullptr;
	PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB = nullptr;
	PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB = nullptr;
	PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB = nullptr;
	PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB = nullptr;
	PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB = nullptr;
	PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB = nullptr;
	PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB = nullptr;
	PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB = nullptr;
	PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB = nullptr;
	PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB = nullptr;
	PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB = nullptr;
	PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB = nullptr;
	PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB = nullptr;
	PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB = nullptr;
	PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB = nullptr;
	PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB = nullptr;
	PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB = nullptr;
	PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB = nullptr;
	PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB = nullptr;
	PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB = nullptr;
	PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB = nullptr;
	PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB = nullptr;
	PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB = nullptr;
	PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB = nullptr;
	PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB = nullptr;

	// GL_ARB_texture_compression
	PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB = nullptr;
	PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB = nullptr;

	// GL_ARB_sampler_objects
	PFNGLGENSAMPLERSPROC glGenSamplersARB = nullptr;
	PFNGLDELETESAMPLERSPROC glDeleteSamplersARB = nullptr;
	PFNGLISSAMPLERPROC glIsSamplerARB = nullptr;
	PFNGLBINDSAMPLERPROC glBindSamplerARB = nullptr;
	PFNGLSAMPLERPARAMETERIPROC glSamplerParameteriARB = nullptr;
	PFNGLSAMPLERPARAMETERIVPROC glSamplerParameterivARB = nullptr;
	PFNGLSAMPLERPARAMETERFPROC glSamplerParameterfARB = nullptr;
	PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfvARB = nullptr;
	PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIivARB = nullptr;
	PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuivARB = nullptr;
	PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameterivARB = nullptr;
	PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIivARB = nullptr;
	PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfvARB = nullptr;
	PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuivARB = nullptr;

	bool IsExtensionSupported(const char* extensions, const char* name)
	{
		if (strstr(extensions, name) == NULL)
		{
			Utils::StreamLoggerWrite(Utils::LOG_LEVEL::Error, "Extension %s is not supported.", name);
			return false;
		}

		return true;
	}

	void InitializeExtensions(void)
	{
		const char* extensions = (const char*)glGetString(GL_EXTENSIONS);

		if (IsExtensionSupported(extensions, "GL_ARB_vertex_buffer_object"))
		{
			LOAD_EXTENSION(PFNGLBINDBUFFERARBPROC, glBindBufferARB);
			LOAD_EXTENSION(PFNGLDELETEBUFFERSARBPROC, glDeleteBuffersARB);
			LOAD_EXTENSION(PFNGLGENBUFFERSARBPROC, glGenBuffersARB);
			LOAD_EXTENSION(PFNGLISBUFFERARBPROC, glIsBufferARB);
			LOAD_EXTENSION(PFNGLBUFFERDATAARBPROC, glBufferDataARB);
			LOAD_EXTENSION(PFNGLBUFFERSUBDATAARBPROC, glBufferSubDataARB);
			LOAD_EXTENSION(PFNGLGETBUFFERSUBDATAARBPROC, glGetBufferSubDataARB);
			LOAD_EXTENSION(PFNGLMAPBUFFERARBPROC, glMapBufferARB);
			LOAD_EXTENSION(PFNGLUNMAPBUFFERARBPROC, glUnmapBufferARB);
			LOAD_EXTENSION(PFNGLGETBUFFERPARAMETERIVARBPROC, glGetBufferParameterivARB);
			LOAD_EXTENSION(PFNGLGETBUFFERPOINTERVARBPROC, glGetBufferPointervARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_map_buffer_range"))
		{
			LOAD_EXTENSION(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_vertex_array_object"))
		{
			LOAD_EXTENSION(PFNGLBINDVERTEXARRAYPROC, glBindVertexArrayARB);
			LOAD_EXTENSION(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArraysARB);
			LOAD_EXTENSION(PFNGLGENVERTEXARRAYSPROC, glGenVertexArraysARB);
			LOAD_EXTENSION(PFNGLISVERTEXARRAYPROC, glIsVertexArrayARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_shader_objects"))
		{
			LOAD_EXTENSION(PFNGLDELETEOBJECTARBPROC, glDeleteObjectARB);
			LOAD_EXTENSION(PFNGLGETHANDLEARBPROC, glGetHandleARB);
			LOAD_EXTENSION(PFNGLDETACHOBJECTARBPROC, glDetachObjectARB);
			LOAD_EXTENSION(PFNGLCREATESHADEROBJECTARBPROC, glCreateShaderObjectARB);
			LOAD_EXTENSION(PFNGLSHADERSOURCEARBPROC, glShaderSourceARB);
			LOAD_EXTENSION(PFNGLCOMPILESHADERARBPROC, glCompileShaderARB);
			LOAD_EXTENSION(PFNGLCREATEPROGRAMOBJECTARBPROC, glCreateProgramObjectARB);
			LOAD_EXTENSION(PFNGLATTACHOBJECTARBPROC, glAttachObjectARB);
			LOAD_EXTENSION(PFNGLLINKPROGRAMARBPROC, glLinkProgramARB);
			LOAD_EXTENSION(PFNGLUSEPROGRAMOBJECTARBPROC, glUseProgramObjectARB);
			LOAD_EXTENSION(PFNGLVALIDATEPROGRAMARBPROC, glValidateProgramARB);
			LOAD_EXTENSION(PFNGLUNIFORM1FARBPROC, glUniform1fARB);
			LOAD_EXTENSION(PFNGLUNIFORM2FARBPROC, glUniform2fARB);
			LOAD_EXTENSION(PFNGLUNIFORM3FARBPROC, glUniform3fARB);
			LOAD_EXTENSION(PFNGLUNIFORM4FARBPROC, glUniform4fARB);
			LOAD_EXTENSION(PFNGLUNIFORM1IARBPROC, glUniform1iARB);
			LOAD_EXTENSION(PFNGLUNIFORM2IARBPROC, glUniform2iARB);
			LOAD_EXTENSION(PFNGLUNIFORM3IARBPROC, glUniform3iARB);
			LOAD_EXTENSION(PFNGLUNIFORM4IARBPROC, glUniform4iARB);
			LOAD_EXTENSION(PFNGLUNIFORMMATRIX2FVARBPROC, glUniformMatrix2fvARB);
			LOAD_EXTENSION(PFNGLUNIFORMMATRIX3FVARBPROC, glUniformMatrix3fvARB);
			LOAD_EXTENSION(PFNGLUNIFORMMATRIX4FVARBPROC, glUniformMatrix4fvARB);
			LOAD_EXTENSION(PFNGLGETOBJECTPARAMETERFVARBPROC, glGetObjectParameterfvARB);
			LOAD_EXTENSION(PFNGLGETOBJECTPARAMETERIVARBPROC, glGetObjectParameterivARB);
			LOAD_EXTENSION(PFNGLGETINFOLOGARBPROC, glGetInfoLogARB);
			LOAD_EXTENSION(PFNGLGETATTACHEDOBJECTSARBPROC, glGetAttachedObjectsARB);
			LOAD_EXTENSION(PFNGLGETUNIFORMLOCATIONARBPROC, glGetUniformLocationARB);
			LOAD_EXTENSION(PFNGLGETACTIVEUNIFORMARBPROC, glGetActiveUniformARB);
			LOAD_EXTENSION(PFNGLGETUNIFORMFVARBPROC, glGetUniformfvARB);
			LOAD_EXTENSION(PFNGLGETUNIFORMIVARBPROC, glGetUniformivARB);
			LOAD_EXTENSION(PFNGLGETSHADERSOURCEARBPROC, glGetShaderSourceARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_vertex_program"))
		{
			LOAD_EXTENSION(PFNGLVERTEXATTRIB1DARBPROC, glVertexAttrib1dARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB1DVARBPROC, glVertexAttrib1dvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB1FARBPROC, glVertexAttrib1fARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB1FVARBPROC, glVertexAttrib1fvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB1SARBPROC, glVertexAttrib1sARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB1SVARBPROC, glVertexAttrib1svARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB2DARBPROC, glVertexAttrib2dARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB2DVARBPROC, glVertexAttrib2dvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB2FARBPROC, glVertexAttrib2fARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB2FVARBPROC, glVertexAttrib2fvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB2SARBPROC, glVertexAttrib2sARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB2SVARBPROC, glVertexAttrib2svARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB3DARBPROC, glVertexAttrib3dARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB3DVARBPROC, glVertexAttrib3dvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB3FARBPROC, glVertexAttrib3fARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB3FVARBPROC, glVertexAttrib3fvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB3SARBPROC, glVertexAttrib3sARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB3SVARBPROC, glVertexAttrib3svARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4NBVARBPROC, glVertexAttrib4NbvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4NIVARBPROC, glVertexAttrib4NivARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4NSVARBPROC, glVertexAttrib4NsvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4NUBARBPROC, glVertexAttrib4NubARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4NUBVARBPROC, glVertexAttrib4NubvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4NUIVARBPROC, glVertexAttrib4NuivARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4NUSVARBPROC, glVertexAttrib4NusvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4BVARBPROC, glVertexAttrib4bvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4DARBPROC, glVertexAttrib4dARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4DVARBPROC, glVertexAttrib4dvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4FARBPROC, glVertexAttrib4fARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4FVARBPROC, glVertexAttrib4fvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4IVARBPROC, glVertexAttrib4ivARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4SARBPROC, glVertexAttrib4sARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4SVARBPROC, glVertexAttrib4svARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4UBVARBPROC, glVertexAttrib4ubvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4UIVARBPROC, glVertexAttrib4uivARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIB4USVARBPROC, glVertexAttrib4usvARB);
			LOAD_EXTENSION(PFNGLVERTEXATTRIBPOINTERARBPROC, glVertexAttribPointerARB);
			LOAD_EXTENSION(PFNGLENABLEVERTEXATTRIBARRAYARBPROC, glEnableVertexAttribArrayARB);
			LOAD_EXTENSION(PFNGLDISABLEVERTEXATTRIBARRAYARBPROC, glDisableVertexAttribArrayARB);
			LOAD_EXTENSION(PFNGLPROGRAMSTRINGARBPROC, glProgramStringARB);
			LOAD_EXTENSION(PFNGLBINDPROGRAMARBPROC, glBindProgramARB);
			LOAD_EXTENSION(PFNGLDELETEPROGRAMSARBPROC, glDeleteProgramsARB);
			LOAD_EXTENSION(PFNGLGENPROGRAMSARBPROC, glGenProgramsARB);
			LOAD_EXTENSION(PFNGLPROGRAMENVPARAMETER4DARBPROC, glProgramEnvParameter4dARB);
			LOAD_EXTENSION(PFNGLPROGRAMENVPARAMETER4DVARBPROC, glProgramEnvParameter4dvARB);
			LOAD_EXTENSION(PFNGLPROGRAMENVPARAMETER4FARBPROC, glProgramEnvParameter4fARB);
			LOAD_EXTENSION(PFNGLPROGRAMENVPARAMETER4FVARBPROC, glProgramEnvParameter4fvARB);
			LOAD_EXTENSION(PFNGLPROGRAMLOCALPARAMETER4DARBPROC, glProgramLocalParameter4dARB);
			LOAD_EXTENSION(PFNGLPROGRAMLOCALPARAMETER4DVARBPROC, glProgramLocalParameter4dvARB);
			LOAD_EXTENSION(PFNGLPROGRAMLOCALPARAMETER4FARBPROC, glProgramLocalParameter4fARB);
			LOAD_EXTENSION(PFNGLPROGRAMLOCALPARAMETER4FVARBPROC, glProgramLocalParameter4fvARB);
			LOAD_EXTENSION(PFNGLGETPROGRAMENVPARAMETERDVARBPROC, glGetProgramEnvParameterdvARB);
			LOAD_EXTENSION(PFNGLGETPROGRAMENVPARAMETERFVARBPROC, glGetProgramEnvParameterfvARB);
			LOAD_EXTENSION(PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC, glGetProgramLocalParameterdvARB);
			LOAD_EXTENSION(PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC, glGetProgramLocalParameterfvARB);
			LOAD_EXTENSION(PFNGLGETPROGRAMIVARBPROC, glGetProgramivARB);
			LOAD_EXTENSION(PFNGLGETPROGRAMSTRINGARBPROC, glGetProgramStringARB);
			LOAD_EXTENSION(PFNGLGETVERTEXATTRIBDVARBPROC, glGetVertexAttribdvARB);
			LOAD_EXTENSION(PFNGLGETVERTEXATTRIBFVARBPROC, glGetVertexAttribfvARB);
			LOAD_EXTENSION(PFNGLGETVERTEXATTRIBIVARBPROC, glGetVertexAttribivARB);
			LOAD_EXTENSION(PFNGLGETVERTEXATTRIBPOINTERVARBPROC, glGetVertexAttribPointervARB);
			LOAD_EXTENSION(PFNGLISPROGRAMARBPROC, glIsProgramARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_vertex_shader"))
		{
			LOAD_EXTENSION(PFNGLBINDATTRIBLOCATIONARBPROC, glBindAttribLocationARB);
			LOAD_EXTENSION(PFNGLGETACTIVEATTRIBARBPROC, glGetActiveAttribARB);
			LOAD_EXTENSION(PFNGLGETATTRIBLOCATIONARBPROC, glGetAttribLocationARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_framebuffer_object"))
		{
			LOAD_EXTENSION(PFNGLISRENDERBUFFERPROC, glIsRenderbufferARB);
			LOAD_EXTENSION(PFNGLBINDRENDERBUFFERPROC, glBindRenderbufferARB);
			LOAD_EXTENSION(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffersARB);
			LOAD_EXTENSION(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffersARB);
			LOAD_EXTENSION(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorageARB);
			LOAD_EXTENSION(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameterivARB);
			LOAD_EXTENSION(PFNGLISFRAMEBUFFERPROC, glIsFramebufferARB);
			LOAD_EXTENSION(PFNGLBINDFRAMEBUFFERPROC, glBindFramebufferARB);
			LOAD_EXTENSION(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffersARB);
			LOAD_EXTENSION(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffersARB);
			LOAD_EXTENSION(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatusARB);
			LOAD_EXTENSION(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1DARB);
			LOAD_EXTENSION(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2DARB);
			LOAD_EXTENSION(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3DARB);
			LOAD_EXTENSION(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbufferARB);
			LOAD_EXTENSION(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameterivARB);
			LOAD_EXTENSION(PFNGLGENERATEMIPMAPPROC, glGenerateMipmapARB);
			LOAD_EXTENSION(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebufferARB);
			LOAD_EXTENSION(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisampleARB);
			LOAD_EXTENSION(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayerARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_multitexture"))
		{
			LOAD_EXTENSION(PFNGLACTIVETEXTUREARBPROC, glActiveTextureARB);
			LOAD_EXTENSION(PFNGLCLIENTACTIVETEXTUREARBPROC, glClientActiveTextureARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1DARBPROC, glMultiTexCoord1dARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1DVARBPROC, glMultiTexCoord1dvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1FARBPROC, glMultiTexCoord1fARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1FVARBPROC, glMultiTexCoord1fvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1IARBPROC, glMultiTexCoord1iARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1IVARBPROC, glMultiTexCoord1ivARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1SARBPROC, glMultiTexCoord1sARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD1SVARBPROC, glMultiTexCoord1svARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2DARBPROC, glMultiTexCoord2dARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2DVARBPROC, glMultiTexCoord2dvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2FARBPROC, glMultiTexCoord2fARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2FVARBPROC, glMultiTexCoord2fvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2IARBPROC, glMultiTexCoord2iARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2IVARBPROC, glMultiTexCoord2ivARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2SARBPROC, glMultiTexCoord2sARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD2SVARBPROC, glMultiTexCoord2svARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3DARBPROC, glMultiTexCoord3dARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3DVARBPROC, glMultiTexCoord3dvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3FARBPROC, glMultiTexCoord3fARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3FVARBPROC, glMultiTexCoord3fvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3IARBPROC, glMultiTexCoord3iARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3IVARBPROC, glMultiTexCoord3ivARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3SARBPROC, glMultiTexCoord3sARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD3SVARBPROC, glMultiTexCoord3svARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4DARBPROC, glMultiTexCoord4dARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4DVARBPROC, glMultiTexCoord4dvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4FARBPROC, glMultiTexCoord4fARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4FVARBPROC, glMultiTexCoord4fvARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4IARBPROC, glMultiTexCoord4iARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4IVARBPROC, glMultiTexCoord4ivARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4SARBPROC, glMultiTexCoord4sARB);
			LOAD_EXTENSION(PFNGLMULTITEXCOORD4SVARBPROC, glMultiTexCoord4svARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_texture_compression"))
		{
			LOAD_EXTENSION(PFNGLCOMPRESSEDTEXIMAGE3DARBPROC, glCompressedTexImage3DARB);
			LOAD_EXTENSION(PFNGLCOMPRESSEDTEXIMAGE2DARBPROC, glCompressedTexImage2DARB);
			LOAD_EXTENSION(PFNGLCOMPRESSEDTEXIMAGE1DARBPROC, glCompressedTexImage1DARB);
			LOAD_EXTENSION(PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC, glCompressedTexSubImage3DARB);
			LOAD_EXTENSION(PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC, glCompressedTexSubImage2DARB);
			LOAD_EXTENSION(PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC, glCompressedTexSubImage1DARB);
			LOAD_EXTENSION(PFNGLGETCOMPRESSEDTEXIMAGEARBPROC, glGetCompressedTexImageARB);
		}

		if (IsExtensionSupported(extensions, "GL_ARB_framebuffer_object"))
		{
			LOAD_EXTENSION(PFNGLGENSAMPLERSPROC, glGenSamplersARB);
			LOAD_EXTENSION(PFNGLDELETESAMPLERSPROC, glDeleteSamplersARB);
			LOAD_EXTENSION(PFNGLISSAMPLERPROC, glIsSamplerARB);
			LOAD_EXTENSION(PFNGLBINDSAMPLERPROC, glBindSamplerARB);
			LOAD_EXTENSION(PFNGLSAMPLERPARAMETERIPROC, glSamplerParameteriARB);
			LOAD_EXTENSION(PFNGLSAMPLERPARAMETERIVPROC, glSamplerParameterivARB);
			LOAD_EXTENSION(PFNGLSAMPLERPARAMETERFPROC, glSamplerParameterfARB);
			LOAD_EXTENSION(PFNGLSAMPLERPARAMETERFVPROC, glSamplerParameterfvARB);
			LOAD_EXTENSION(PFNGLSAMPLERPARAMETERIIVPROC, glSamplerParameterIivARB);
			LOAD_EXTENSION(PFNGLSAMPLERPARAMETERIUIVPROC, glSamplerParameterIuivARB);
			LOAD_EXTENSION(PFNGLGETSAMPLERPARAMETERIVPROC, glGetSamplerParameterivARB);
			LOAD_EXTENSION(PFNGLGETSAMPLERPARAMETERIIVPROC, glGetSamplerParameterIivARB);
			LOAD_EXTENSION(PFNGLGETSAMPLERPARAMETERFVPROC, glGetSamplerParameterfvARB);
			LOAD_EXTENSION(PFNGLGETSAMPLERPARAMETERIUIVPROC, glGetSamplerParameterIuivARB);
		}
	}

	namespace GL_ARB_VertexBufferObject
	{
		void BindBuffer(UInt target, UInt buffer, const char* breakpointLocation)
		{
			glBindBufferARB(target, buffer);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void UnbindBuffer(UInt target, const char* breakpointLocation)
		{
			glBindBufferARB(target, 0);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void DeleteBuffers(UInt num, UInt* buffers)
		{
			glDeleteBuffersARB(num, buffers);
		}

		void GenerateBuffers(UInt num, UInt* buffers, const char* breakpointLocation)
		{
			glGenBuffersARB(num, buffers);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		bool IsBuffer(UInt buffer)
		{
			return glIsBufferARB(buffer);
		}

		void BufferData(UInt target, UInt size, const void* data, UInt usage, const char* breakpointLocation)
		{
			glBufferDataARB(target, size, data, usage);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void BufferSubData(UInt target, UInt offset, UInt size, const void* data, const char* breakpointLocation)
		{
			glBufferSubDataARB(target, offset, size, data);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetBufferSubData(UInt target, int offset, int size, void* data, const char* breakpointLocation)
		{
			glGetBufferSubDataARB(target, offset, size, data);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void* MapBuffer(UInt target, UInt access, const char* breakpointLocation)
		{
			void* mappedBuffer = glMapBufferARB(target, access);
			CHECK_OPENGL_ERROR(breakpointLocation);
			return mappedBuffer;
		}

		void UnmapBuffer(UInt target, const char* breakpointLocation)
		{
			glUnmapBufferARB(target);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetBufferParameterI(UInt target, UInt value, int* params, const char* breakpointLocation)
		{
			glGetBufferParameterivARB(target, value, params);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetBufferPointer(UInt target, UInt value, void** params, const char* breakpointLocation)
		{
			glGetBufferPointervARB(target, value, params);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}
	}

	namespace GL_ARB_MapBufferRange
	{
		void* MapBufferRange(UInt target, int offset, int length, UInt access, const char* breakpointLocation)
		{
			void* mappedBuffer = glMapBufferRange(target, offset, length, access);
			CHECK_OPENGL_ERROR(breakpointLocation);
			return mappedBuffer;
		}
	}

	namespace GL_ARB_VertexArrayObject
	{
		void BindVertexArray(UInt array, const char* breakpointLocation)
		{
			glBindVertexArrayARB(array);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void UnbindVertexArray(const char* breakpointLocation)
		{
			glBindVertexArrayARB(0);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void DeleteVertexArrays(int num, UInt* arrays)
		{
			glDeleteVertexArraysARB(num, arrays);
		}

		void GenerateVertexArrays(UInt num, UInt* arrays, const char* breakpointLocation)
		{
			glGenVertexArraysARB(num, arrays);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		bool IsVertexArray(UInt array)
		{
			return glIsVertexArrayARB(array);
		}
	}

	namespace GL_ARB_ShaderObjects
	{
		void DeleteObject(UInt obj)
		{
			glDeleteObjectARB(obj);
		}

		UInt GetHandle(UInt value)
		{
			return glGetHandleARB(value);
		}

		void DetachObject(UInt containerObj, UInt attachedObj, const char* breakpointLocation)
		{
			glDetachObjectARB(containerObj, attachedObj);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		UInt CreateShaderObject(UInt shaderType, const char* breakpointLocation)
		{
			UInt objectID = glCreateShaderObjectARB(shaderType);
			CHECK_OPENGL_ERROR(breakpointLocation);
			return objectID;
		}

		void ShaderSource(UInt objectID, int count, const char** source, const int* length, const char* breakpointLocation)
		{
			glShaderSourceARB(objectID, count, (const GLcharARB**)&source, length);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void CompileShader(UInt objectID, const char* breakpointLocation)
		{
			glCompileShaderARB(objectID);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		UInt CreateProgramObject(const char* breakpointLocation)
		{
			UInt result = glCreateProgramObjectARB();
			CHECK_OPENGL_ERROR(breakpointLocation);
			return result;
		}

		void AttachObject(UInt containerObj, UInt obj, const char* breakpointLocation)
		{
			glAttachObjectARB(containerObj, obj);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void LinkProgram(UInt programObj, const char* breakpointLocation)
		{
			glLinkProgramARB(programObj);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void UseProgramObject(UInt programObj, const char* breakpointLocation)
		{
			glUseProgramObjectARB(programObj);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void ValidateProgram(UInt programObj, const char* breakpointLocation)
		{
			glValidateProgramARB(programObj);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform1F(int location, float value0, const char* breakpointLocation)
		{
			glUniform1fARB(location, value0);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform2F(int location, float value0, float value1, const char* breakpointLocation)
		{
			glUniform2fARB(location, value0, value1);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform3F(int location, float value0, float value1, float value2, const char* breakpointLocation)
		{
			glUniform3fARB(location, value0, value1, value2);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform4F(int location, float value0, float value1, float value2, float value3, const char* breakpointLocation)
		{
			glUniform4fARB(location, value0, value1, value2, value3);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform1I(int location, int value0, const char* breakpointLocation)
		{
			glUniform1iARB(location, value0);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform2I(int location, int value0, int value1, const char* breakpointLocation)
		{
			glUniform2iARB(location, value0, value1);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform3I(int location, int value0, int value1, int value2, const char* breakpointLocation)
		{
			glUniform3iARB(location, value0, value1, value2);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void Uniform4I(int location, int value0, int value1, int value2, int value3, const char* breakpointLocation)
		{
			glUniform4iARB(location, value0, value1, value2, value3);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void UniformMatrix2(int location, int count, bool transpose, const float* value, const char* breakpointLocation)
		{
			glUniformMatrix2fvARB(location, count, transpose, value);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void UniformMatrix3(int location, int count, bool transpose, const float* value, const char* breakpointLocation)
		{
			glUniformMatrix3fvARB(location, count, transpose, value);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void UniformMatrix4(int location, int count, bool transpose, const float* value, const char* breakpointLocation)
		{
			glUniformMatrix4fvARB(location, count, transpose, value);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetObjectParameterF(UInt obj, int value, float* params, const char* breakpointLocation)
		{
			glGetObjectParameterfvARB(obj, value, params);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetObjectParameterI(UInt obj, int value, int* params, const char* breakpointLocation)
		{
			glGetObjectParameterivARB(obj, value, params);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetInfoLog(UInt obj, int maxLength, int* length, char* infoLog, const char* breakpointLocation)
		{
			glGetInfoLogARB(obj, maxLength, length, infoLog);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetAttachedObjects(UInt containerObj, int maxCount, int* count, UInt* obj, const char* breakpointLocation)
		{
			glGetAttachedObjectsARB(containerObj, maxCount, count, obj);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		int GetUniformLocation(UInt programObj, const char* name, const char* breakpointLocation)
		{
			int result = glGetUniformLocationARB(programObj, name);
			CHECK_OPENGL_ERROR(breakpointLocation);
			return result;
		}

		void GetActiveUniform(UInt programObj, UInt index, int maxLength, int* length, int* size, UInt* type, char* name, const char* breakpointLocation)
		{
			glGetActiveUniformARB(programObj, index, maxLength, length, size, type, name);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetUniformF(UInt programObj, int location, float* params, const char* breakpointLocation)
		{
			glGetUniformfvARB(programObj, location, params);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetUniformI(UInt programObj, int location, int* params, const char* breakpointLocation)
		{
			glGetUniformivARB(programObj, location, params);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetShaderSource(UInt obj, int maxLength, int* length, char* source, const char* breakpointLocation)
		{
			glGetShaderSourceARB(obj, maxLength, length, source);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}
	}

	namespace GL_ARB_VertexProgram
	{
		//glVertexAttrib1dARB
		//glVertexAttrib1dvARB
		//glVertexAttrib1fARB
		//glVertexAttrib1fvARB
		//glVertexAttrib1sARB
		//glVertexAttrib1svARB
		//glVertexAttrib2dARB
		//glVertexAttrib2dvARB
		//glVertexAttrib2fARB
		//glVertexAttrib2fvARB
		//glVertexAttrib2sARB
		//glVertexAttrib2svARB
		//glVertexAttrib3dARB
		//glVertexAttrib3dvARB
		//glVertexAttrib3fARB
		//glVertexAttrib3fvARB
		//glVertexAttrib3sARB
		//glVertexAttrib3svARB
		//glVertexAttrib4NbvARB
		//glVertexAttrib4NivARB
		//glVertexAttrib4NsvARB
		//glVertexAttrib4NubARB
		//glVertexAttrib4NubvARB
		//glVertexAttrib4NuivARB
		//glVertexAttrib4NusvARB
		//glVertexAttrib4bvARB
		//glVertexAttrib4dARB
		//glVertexAttrib4dvARB
		//glVertexAttrib4fARB
		//glVertexAttrib4fvARB
		//glVertexAttrib4ivARB
		//glVertexAttrib4sARB
		//glVertexAttrib4svARB
		//glVertexAttrib4ubvARB
		//glVertexAttrib4uivARB
		//glVertexAttrib4usvARB
		
		void VertexAttributePointer(UInt index, int size, UInt type, bool normalized, int stride, const void* pointer, const char* breakpointLocation)
		{
			glVertexAttribPointerARB(index, size, type, normalized, stride, pointer);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void EnableVertexAttributeArray(UInt index, const char* breakpointLocation)
		{
			glEnableVertexAttribArrayARB(index);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void DisableVertexAttributeArray(UInt index, const char* breakpointLocation)
		{
			glDisableVertexAttribArrayARB(index);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void ProgramString(UInt target, UInt format, int length, const void* str, const char* breakpointLocation)
		{
			glProgramStringARB(target, format, length, str);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glBindProgramARB

		void DeletePrograms(int num, const UInt* programs, const char* breakpointLocation)
		{
			glDeleteProgramsARB(num, programs);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glGenProgramsARB
		//glProgramEnvParameter4dARB
		//glProgramEnvParameter4dvARB
		//glProgramEnvParameter4fARB
		//glProgramEnvParameter4fvARB
		//glProgramLocalParameter4dARB
		//glProgramLocalParameter4dvARB
		//glProgramLocalParameter4fARB
		//glProgramLocalParameter4fvARB
		//glGetProgramEnvParameterdvARB
		//glGetProgramEnvParameterfvARB
		//glGetProgramLocalParameterdvARB
		//glGetProgramLocalParameterfvARB
		//glGetProgramivARB
		//glGetProgramStringARB
		//glGetVertexAttribdvARB
		//glGetVertexAttribfvARB
		//glGetVertexAttribivARB
		//glGetVertexAttribPointervARB
		//glIsProgramARB
	}

	namespace GL_ARB_VertexShader
	{
		void BindAttributeLocation(UInt programObj, int index, const char* name, const char* breakpointLocation)
		{
			glBindAttribLocationARB(programObj, index, name);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void GetActiveAttribute(UInt programObj, int index, int maxLength, int* length, int* size, UInt* type, char* name, const char* breakpointLocation)
		{
			glGetActiveAttribARB(programObj, index, maxLength, length, size, type, name);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		int GetAttributeLocation(UInt programObj, const char* name, const char* breakpointLocation)
		{
			int result = glGetAttribLocationARB(programObj, name);
			CHECK_OPENGL_ERROR(breakpointLocation);
			return result;
		}
	}

	namespace GL_ARB_FramebufferObject
	{
		bool IsRenderbuffer(UInt renderBuffer)
		{
			return glIsRenderbufferARB(renderBuffer);
		}
		
		void BindRenderbuffer(UInt target, UInt renderBuffer, const char* breakpointLocation)
		{
			glBindRenderbufferARB(target, renderBuffer);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void DeleteRenderbuffers(int num, UInt* renderBuffers)
		{
			glDeleteRenderbuffersARB(num, renderBuffers);
		}
		
		void GenRenderbuffers(int num, UInt* renderBuffers, const char* breakpointLocation)
		{
			glGenRenderbuffersARB(num, renderBuffers);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void RenderbufferStorage(UInt target, UInt internalFormat, int width, int height, const char* breakpointLocation)
		{
			glRenderbufferStorageARB(target, internalFormat, width, height);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glGetRenderbufferParameterivARB
		
		bool IsFramebuffer(UInt framebuffer)
		{
			return glIsFramebufferARB(framebuffer);
		}
		
		void BindFramebuffer(UInt target, UInt frameBuffer, const char* breakpointLocation)
		{
			glBindFramebufferARB(target, frameBuffer);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void DeleteFramebuffers(int num, UInt* frameBuffers)
		{
			glDeleteFramebuffersARB(num, frameBuffers);
		}
		
		void GenFramebuffers(int num, UInt* frameBuffers, const char* breakpointLocation)
		{
			glGenFramebuffersARB(num, frameBuffers);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		bool CheckFramebufferStatus(UInt target, const char* breakpointLocation)
		{
			bool result = glCheckFramebufferStatusARB(target);
			CHECK_OPENGL_ERROR(breakpointLocation);
			return result;
		}

		//glFramebufferTexture1DARB
		
		void FramebufferTexture2D(UInt target, UInt attachment, UInt texureTarget, UInt texture, int level, const char* breakpointLocation)
		{
			glFramebufferTexture2DARB(target, attachment, texureTarget, texture, level);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glFramebufferTexture3DARB

		void FramebufferRenderbuffer(UInt target, UInt attachment, UInt renderBufferTarget, UInt renderBuffer, const char* breakpointLocation)
		{
			glFramebufferRenderbufferARB(target, attachment, renderBufferTarget, renderBuffer);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}
		//glGetFramebufferAttachmentParameterivARB
		
		void GenerateMipmap(UInt target, const char* breakpointLocation)
		{
			glGenerateMipmapARB(target);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glBlitFramebufferARB
		//glRenderbufferStorageMultisampleARB
		//glFramebufferTextureLayerARB
	}

	namespace GL_ARB_Multitexture
	{
		void ActiveTexture(UInt texture, const char* breakpointLocation)
		{
			glActiveTextureARB(texture);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		void ClientActiveTexture(UInt texture, const char* breakpointLocation)
		{
			glClientActiveTextureARB(texture);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glClientActiveTextureARB
		//glMultiTexCoord1dARB
		//glMultiTexCoord1dvARB
		//glMultiTexCoord1fARB
		//glMultiTexCoord1fvARB
		//glMultiTexCoord1iARB
		//glMultiTexCoord1ivARB
		//glMultiTexCoord1sARB
		//glMultiTexCoord1svARB
		//glMultiTexCoord2dARB
		//glMultiTexCoord2dvARB
		//glMultiTexCoord2fARB
		//glMultiTexCoord2fvARB
		//glMultiTexCoord2iARB
		//glMultiTexCoord2ivARB
		//glMultiTexCoord2sARB
		//glMultiTexCoord2svARB
		//glMultiTexCoord3dARB
		//glMultiTexCoord3dvARB
		//glMultiTexCoord3fARB
		//glMultiTexCoord3fvARB
		//glMultiTexCoord3iARB
		//glMultiTexCoord3ivARB
		//glMultiTexCoord3sARB
		//glMultiTexCoord3svARB
		//glMultiTexCoord4dARB
		//glMultiTexCoord4dvARB
		//glMultiTexCoord4fARB
		//glMultiTexCoord4fvARB
		//glMultiTexCoord4iARB
		//glMultiTexCoord4ivARB
		//glMultiTexCoord4sARB
		//glMultiTexCoord4svARB
	}

	namespace GL_ARB_TextureCompression
	{
		//glCompressedTexImage3DARB
		//glCompressedTexImage2DARB
		//glCompressedTexImage1DARB
		//glCompressedTexSubImage3DARB
		//glCompressedTexSubImage2DARB
		//glCompressedTexSubImage1DARB
		//glGetCompressedTexImageARB
	}

	namespace GL_ARB_SamplerObjects
	{
		void GenSamplers(int count, UInt* samplers, const char* breakpointLocation)
		{
			glGenSamplersARB(count, samplers);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glDeleteSamplersARB
		//glIsSamplerARB
		//glBindSamplerARB
		
		void SamplerParameterI(UInt sampler, UInt value, int param, const char* breakpointLocation)
		{
			glSamplerParameteriARB(sampler, value, param);
			CHECK_OPENGL_ERROR(breakpointLocation);
		}

		//glSamplerParameterivARB
		//glSamplerParameterfARB
		//glSamplerParameterfvARB
		//glSamplerParameterIivARB
		//glSamplerParameterIuivARB
		//glGetSamplerParameterivARB
		//glGetSamplerParameterIivARB
		//glGetSamplerParameterfvARB
		//glGetSamplerParameterIuivARB
	}
}