/*	build_shaders.py loads shaders into this header at compile time.
 *	This makes the program more portable as the shader sources are
 *	included in the binary.
 */
#pragma once
extern const char* Circle_frag;extern const char* Circle_vert;extern const char* Simple_frag;extern const char* Simple_vert;extern const char* Uniforms_frag;