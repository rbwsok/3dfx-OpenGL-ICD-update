OpenGL 1.1 Client Driver update

08.07.2003
 + ��������� ����������: 
   GL_EXT_texture_edge_clamp,
   GL_SGI_texture_edge_clamp,
   GL_ARB_texture_env_add,
   GL_ARB_point_parameters,
   GL_3DFX_tbuffer,
   GL_WIN_swap_hint,
   GL_SGI_index_func,
   GL_SGI_index_material,
   GL_EXT_draw_range_elements,
   GL_EXT_color_table,
   GL_EXT_color_subtable,
   GL_EXT_blend_minmax.
 + ��������� ������� glTbufferMask3DFX - � ������������ � ��������
   opengl ���������� ��� GL_3DFX_tbuffer.
   � ������������ opengl ��������� ������� glTBufferMask3DFX.   
09.07.2003
 + ��������� ����������: 
   GL_SGI_cull_vertex,
   GL_EXT_multi_draw_arrays,
   GL_SUN_multi_draw_arrays,
   GL_IBM_multimode_draw_arrays,
   GL_EXT_texture_object,
   GL_EXT_polygon_offset,
   GL_EXT_blend_logic_op,
   GL_EXT_texture,
   GL_EXT_subtexture,
   GL_EXT_copy_texture,
10.07.2003
 + ��������� ����������: 
   GL_WIN_draw_range_elements,
   GL_ARB_transpose_matrix,
   GL_ARB_texture_env_combine,

///////////////
opengl 1.2.1
1.  - EXT_texture3D - ��������� ����������
2.  + EXT_bgra - ��������� �����������
3.  + EXT_packed_pixels - ��������� �����������
4.  + EXT_rescale_normal
5.  - EXT_separate_specular_color
6.  + SGIS_texture_edge_clamp - ��������� �����������
7.  + SGIS_texture_lod
8.  ? EXT_draw_range_elements - ��������� �����������
9.  - EXT_color_table - ��������� �����������
10. - EXT_color_subtable - ��������� �����������
11. - EXT_convolution
12. - HP_convolution_border_modes
13. - SGI_color_matrix
14. - EXT_histogram
15. - EXT_blend_color
16. - EXT_blend_minmax - ��������� ����������� (?)
17. + EXT_blend_subtract - ��������� �����������
18. + ARB_multitexture - ��������� �����������

///////////////
opengl 1.3
1.  + ARB_texture_compression - ��������� �����������
2.  - ARB_texture_cube_map - ��������� ����������
3.  + ARB_multisample
4.  + ARB_multitexture - ��������� �����������
5.  + ARB_texture_env_add - ��������� �����������
6.  + ARB_texture_env_combine - ��������� ����������� (�� ���������)
7.  - ARB_texture_env_dot3 - ��������� ����������
8.  - ARB_texture_border_clamp
9.  + ARB_transpose_matrix - ��������� �����������


///////////////////////////////////////////////////////////////

// 1.1 build 003 (08.08.2003)
���������� ������. ������� �������� ��������� ���������� � ���������� v1.0 -> v1.1
 + GL_ARB_multisample - �������� ��������� (�������� ����� GL_3DFX_multisample)

// 1.1 build 004 (03.09.2003)
��������� ��������:
 + GL_NV_fence
 + GL_NV_vertex_array_range
 + GL_NV_vertex_array_range2
 + GL_NV_pixel_data_range

// 1.1 build 005 (08.09.2003)
���������:
 + GL_MESA_window_pos
 + GL_ARB_window_pos

// 1.1 build 006 (12.09.2003)
���������:
 + GL_SGIS_generate_mipmap

// 1.1 build 007 (01.01.2004)
���������:
 + GL_EXT_generate_mipmap
 * ���������� ������ � GL_3DFX_multisample (� GL_ARB_multisample) ���
   Voodoo5 5500 �� ���� ������� ���������� ������� ��� FSAA.

// 1.1 build 008 (20.05.2004)
���������:
 + GL_ARB_vertex_buffer_object

// 1.1 build 009 (30.06.2004)
���������:
 ! �������� OpenGL control �������
 ! ���������� ���������� ���� �������� RGB/RGBA ������� ����� DXTC.
 + GL_ARB_texture_env_combine - �������� ��������� (�������� ������ ����� OpenGL control)
 + GL_EXT_texture_filter_anisotropic - fake. ������������� ������������, �� ������ �� ������.
 + GL_NV_light_max_exponent - fake. ������������� ������������, �� ������ �� ������.
 * ���������� ���������� � GL_IBM_multimode_draw_arrays � ������������ � ����������� �������� ����������

// 1.1 build 010 (7.07.2004)
���������:
 ! ���������, � ���� ���������� �������������. 
   �� �����������  - dll'�� ����������� ������� ���������� opengl32.dll. 
   �� ������������ - ��������� icd v1.0.0.0508 ��� Voodoo2. � ������ ����� ���������� ����� ������ 3dfx icd,
   �� ���� �������������� �� ������������ ������� ������� ��� ��������� Voodoo.
   ���� �� Voodoo Graphics - �� �� ���� ���������.
   ������ �� Voodoo2 ����������� � SLI � ��������� ������, � ����� � ���������������� �������������, ����� Voodoo2
   ������������ � ��������� �����������.   
 ! ��������� OpenGL Control utilite. ��� Voodoo2 ����� ������ �������������� ��������� ���������� �� 2d �����.
   ��� ����� ��� ����������� ������ ����, ��� �������� ����������� �� 2/3 ���� � ��������� ����������. 
 * ��������� ��������� ���� � ��������������� �������.
 * ���������� ���������� GL_ARB_vertex_buffer_object.
 * ���������� ���������� GL_SGIS_generate_mipmap/GL_EXT_generate_mipmap.
 + GL_APPLE_packed_pixels
 + GL_EXT_rescale_normal

// 1.1 build 011 (21.01.2005)
���������:
 * ���������� �������������� �������.
 * GL_ARB_texture_env_combine �� ��������� ��������.

// 1.1 build 012 (25.01.2006)
���������:
 * ������������ ���������� ���������
 * ���������� ������ � GL_3DFX_multisample (� GL_ARB_multisample) ���
   Voodoo4 �� ���� ������� ���������� ������� ��� FSAA.
 * ��������������� GL_EXT_texture_filter_anisotropic
 * ���������� ���������� GL_ARB_transpose_matrix.
 + GL_ARB_point_sprite
 + GL_NV_point_sprite
 + GL_NV_multisample_filter_hint
 + GL_EXT_texture_lod_bias 
 + GL_SGIS_texture_lod

������� ���������� (Voodoo5):

 EXTENSIONS: GL_3DFX_multisample                  - ����
             GL_3DFX_tbuffer                      - ���������
             GL_3DFX_texture_compression_FXT1     - ����
             GL_APPLE_packed_pixels               - ���������
             GL_ARB_multisample                   - ���������
             GL_ARB_multitexture                  - ����
             GL_ARB_point_parameters              - ���������
             GL_ARB_point_sprite                  - ���������
             GL_ARB_texture_compression           - ����
             GL_ARB_texture_env_add               - ���������
             GL_ARB_texture_env_combine           - ��������� (�������� ���������)
             GL_ARB_transpose_matrix              - ���������
             GL_ARB_vertex_buffer_object          - ���������
             GL_ARB_window_pos                    - ���������
             GL_EXT_abgr                          - ����
             GL_EXT_bgra                          - ����
             GL_EXT_blend_subtract                - ����
             GL_EXT_clip_volume_hint              - ����
             GL_EXT_compiled_vertex_array         - ����
             GL_EXT_fog_coord                     - ����
             GL_EXT_generate_mipmap               - ���������
             GL_EXT_multi_draw_arrays             - ���������
             GL_EXT_packed_pixels                 - ����
             GL_EXT_paletted_texture              - ��������� (Colourless)
             GL_EXT_point_parameters              - ����
             GL_EXT_rescale_normal                - ���������
             GL_EXT_shared_texture_palette        - ��������� (Colourless)
             GL_EXT_stencil_wrap                  - ����
             GL_EXT_texture_compression_s3tc      - ����
             GL_EXT_texture_edge_clamp            - ���������
             GL_EXT_texture_env_add               - ����
             GL_EXT_texture_env_combine           - ����
             GL_EXT_texture_filter_anisotropic    - ���������
             GL_EXT_texture_lod_bias              - ���������
             GL_EXT_vertex_array                  - ����
             GL_IBM_multimode_draw_arrays         - ���������
             GL_MESA_window_pos                   - ���������
             GL_NV_fence                          - ���������
             GL_NV_light_max_exponent             - ���������
             GL_NV_multisample_filter_hint        - ���������
             GL_NV_pixel_data_range               - ���������
             GL_NV_point_sprite                   - ���������
             GL_NV_vertex_array_range             - ���������
             GL_NV_vertex_array_range2            - ���������
             GL_S3_s3tc                           - ����
             GL_SGI_texture_edge_clamp            - ��������� 
             GL_SGIS_generate_mipmap              - ��������� 
             GL_SGIS_multitexture                 - ����
             GL_SGIS_texture_edge_clamp           - ����
             GL_SGIS_texture_lod                  - ���������
             GL_SUN_multi_draw_arrays             - ��������� 
             GL_WIN_swap_hint                     - ���������                     
             WGL_3DFX_gamma_control               - ����
             WGL_ARB_extensions_string            - ����
             WGL_EXT_extensions_string            - ����
             WGL_EXT_swap_control                 - ����
 EXT string: WGL_3DFX_gamma_control               - ����
             WGL_3DFX_multisample                 - ����
             WGL_ARB_extensions_string            - ����
             WGL_ARB_multisample                  - ��������� 
             WGL_ARB_pixel_format                 - ����
             WGL_EXT_extensions_string            - ����
             WGL_EXT_swap_control                 - ����
 ARB string: WGL_3DFX_gamma_control               - ����
             WGL_3DFX_multisample                 - ����
             WGL_ARB_extensions_string            - ����
             WGL_ARB_multisample                  - ��������� 
             WGL_ARB_pixel_format                 - ����
             WGL_EXT_extensions_string            - ����
             WGL_EXT_swap_control                 - ����
 
/////////////////////////////////////////////////////////////
// ����������
/////////////////////////////////////////////////////////////
1. learnig_var demo (nVidia)
2. winpos demo (MESA) 
3. RadeonAutoMipGen demo (ATI)
4. OpenGL Extensions Viewer v2.06.261 (Realtech VR)
