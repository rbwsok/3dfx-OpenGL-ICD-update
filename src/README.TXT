OpenGL 1.1 Client Driver update

08.07.2003
 + Добавлены расширения: 
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
 + Добавлена функция glTbufferMask3DFX - в соответствии с реестром
   opengl расширений для GL_3DFX_tbuffer.
   В оригинальном opengl находится функция glTBufferMask3DFX.   
09.07.2003
 + Добавлены расширения: 
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
 + Добавлены расширения: 
   GL_WIN_draw_range_elements,
   GL_ARB_transpose_matrix,
   GL_ARB_texture_env_combine,

///////////////
opengl 1.2.1
1.  - EXT_texture3D - поддержка невозможна
2.  + EXT_bgra - поддержка реализована
3.  + EXT_packed_pixels - поддержка реализована
4.  + EXT_rescale_normal
5.  - EXT_separate_specular_color
6.  + SGIS_texture_edge_clamp - поддержка реализована
7.  + SGIS_texture_lod
8.  ? EXT_draw_range_elements - поддержка реализована
9.  - EXT_color_table - поддержка реализована
10. - EXT_color_subtable - поддержка реализована
11. - EXT_convolution
12. - HP_convolution_border_modes
13. - SGI_color_matrix
14. - EXT_histogram
15. - EXT_blend_color
16. - EXT_blend_minmax - поддержка реализована (?)
17. + EXT_blend_subtract - поддержка реализована
18. + ARB_multitexture - поддержка реализована

///////////////
opengl 1.3
1.  + ARB_texture_compression - поддержка реализована
2.  - ARB_texture_cube_map - поддержка невозможна
3.  + ARB_multisample
4.  + ARB_multitexture - поддержка реализована
5.  + ARB_texture_env_add - поддержка реализована
6.  + ARB_texture_env_combine - поддержка реализована (не полностью)
7.  - ARB_texture_env_dot3 - поддержка невозможна
8.  - ARB_texture_border_clamp
9.  + ARB_transpose_matrix - поддержка реализована


///////////////////////////////////////////////////////////////

// 1.1 build 003 (08.08.2003)
стабильная версия. удалены возможно нерабочие ресширения и расширения v1.0 -> v1.1
 + GL_ARB_multisample - неполная поддержка (эмуляция через GL_3DFX_multisample)

// 1.1 build 004 (03.09.2003)
добавлена эмуляция:
 + GL_NV_fence
 + GL_NV_vertex_array_range
 + GL_NV_vertex_array_range2
 + GL_NV_pixel_data_range

// 1.1 build 005 (08.09.2003)
добавлены:
 + GL_MESA_window_pos
 + GL_ARB_window_pos

// 1.1 build 006 (12.09.2003)
добавлены:
 + GL_SGIS_generate_mipmap

// 1.1 build 007 (01.01.2004)
добавлены:
 + GL_EXT_generate_mipmap
 * исправлена ошибка в GL_3DFX_multisample (и GL_ARB_multisample) для
   Voodoo5 5500 на счет запроса количества сэмплов для FSAA.

// 1.1 build 008 (20.05.2004)
добавлены:
 + GL_ARB_vertex_buffer_object

// 1.1 build 009 (30.06.2004)
добавлены:
 ! создание OpenGL control утилиты
 ! реализация компрессии всех входящих RGB/RGBA текстур через DXTC.
 + GL_ARB_texture_env_combine - неполная поддержка (доступно только через OpenGL control)
 + GL_EXT_texture_filter_anisotropic - fake. соответствует спецификации, но ничего не делает.
 + GL_NV_light_max_exponent - fake. соответствует спецификации, но ничего не делает.
 * исправлена неточность в GL_IBM_multimode_draw_arrays в соответствии с официальным реестром расширений

// 1.1 build 010 (7.07.2004)
добавлены:
 ! полностью, с нуля переписана инициализация. 
   из недостатков  - dll'ка обязательно требует называться opengl32.dll. 
   из нововведений - поддержка icd v1.0.0.0508 для Voodoo2. в теории можно поддержать любую версию 3dfx icd,
   но пока останавливаюсь на максимальных рабочих релизах для различных Voodoo.
   была бы Voodoo Graphics - ее бы тоже прикрутил.
   работа на Voodoo2 проверялась в SLI и одинарном режиме, а также в мультимониторных конфигурациях, когда Voodoo2
   подключалась к различным видеокартам.   
 ! обновлена OpenGL Control utilite. для Voodoo2 можно задать принудительное изменение расширение на 2d карте.
   это нужно для исправления такого бага, как смещение изображения на 2/3 вниз в некоторых программах. 
 * исправлен небольшой глюк с автокомпрессией текстур.
 * исправлена реализация GL_ARB_vertex_buffer_object.
 * исправлена реализация GL_SGIS_generate_mipmap/GL_EXT_generate_mipmap.
 + GL_APPLE_packed_pixels
 + GL_EXT_rescale_normal

// 1.1 build 011 (21.01.2005)
добавлены:
 * исправлена автокомпрессия текстур.
 * GL_ARB_texture_env_combine по умолчанию включено.

// 1.1 build 012 (25.01.2006)
добавлены:
 * переработана внутренняя структура
 * исправлена ошибка в GL_3DFX_multisample (и GL_ARB_multisample) для
   Voodoo4 на счет запроса количества сэмплов для FSAA.
 * скорректировано GL_EXT_texture_filter_anisotropic
 * исправлена реализация GL_ARB_transpose_matrix.
 + GL_ARB_point_sprite
 + GL_NV_point_sprite
 + GL_NV_multisample_filter_hint
 + GL_EXT_texture_lod_bias 
 + GL_SGIS_texture_lod

текущие расширения (Voodoo5):

 EXTENSIONS: GL_3DFX_multisample                  - было
             GL_3DFX_tbuffer                      - добавлено
             GL_3DFX_texture_compression_FXT1     - было
             GL_APPLE_packed_pixels               - добавлено
             GL_ARB_multisample                   - добавлено
             GL_ARB_multitexture                  - было
             GL_ARB_point_parameters              - добавлено
             GL_ARB_point_sprite                  - добавлено
             GL_ARB_texture_compression           - было
             GL_ARB_texture_env_add               - добавлено
             GL_ARB_texture_env_combine           - добавлено (неполная поддержка)
             GL_ARB_transpose_matrix              - добавлено
             GL_ARB_vertex_buffer_object          - добавлено
             GL_ARB_window_pos                    - добавлено
             GL_EXT_abgr                          - было
             GL_EXT_bgra                          - было
             GL_EXT_blend_subtract                - было
             GL_EXT_clip_volume_hint              - было
             GL_EXT_compiled_vertex_array         - было
             GL_EXT_fog_coord                     - было
             GL_EXT_generate_mipmap               - добавлено
             GL_EXT_multi_draw_arrays             - добавлено
             GL_EXT_packed_pixels                 - было
             GL_EXT_paletted_texture              - добавлено (Colourless)
             GL_EXT_point_parameters              - было
             GL_EXT_rescale_normal                - добавлено
             GL_EXT_shared_texture_palette        - добавлено (Colourless)
             GL_EXT_stencil_wrap                  - было
             GL_EXT_texture_compression_s3tc      - было
             GL_EXT_texture_edge_clamp            - добавлено
             GL_EXT_texture_env_add               - было
             GL_EXT_texture_env_combine           - было
             GL_EXT_texture_filter_anisotropic    - добавлено
             GL_EXT_texture_lod_bias              - добавлено
             GL_EXT_vertex_array                  - было
             GL_IBM_multimode_draw_arrays         - добавлено
             GL_MESA_window_pos                   - добавлено
             GL_NV_fence                          - добавлено
             GL_NV_light_max_exponent             - добавлено
             GL_NV_multisample_filter_hint        - добавлено
             GL_NV_pixel_data_range               - добавлено
             GL_NV_point_sprite                   - добавлено
             GL_NV_vertex_array_range             - добавлено
             GL_NV_vertex_array_range2            - добавлено
             GL_S3_s3tc                           - было
             GL_SGI_texture_edge_clamp            - добавлено 
             GL_SGIS_generate_mipmap              - добавлено 
             GL_SGIS_multitexture                 - было
             GL_SGIS_texture_edge_clamp           - было
             GL_SGIS_texture_lod                  - добавлено
             GL_SUN_multi_draw_arrays             - добавлено 
             GL_WIN_swap_hint                     - добавлено                     
             WGL_3DFX_gamma_control               - было
             WGL_ARB_extensions_string            - было
             WGL_EXT_extensions_string            - было
             WGL_EXT_swap_control                 - было
 EXT string: WGL_3DFX_gamma_control               - было
             WGL_3DFX_multisample                 - было
             WGL_ARB_extensions_string            - было
             WGL_ARB_multisample                  - добавлено 
             WGL_ARB_pixel_format                 - было
             WGL_EXT_extensions_string            - было
             WGL_EXT_swap_control                 - было
 ARB string: WGL_3DFX_gamma_control               - было
             WGL_3DFX_multisample                 - было
             WGL_ARB_extensions_string            - было
             WGL_ARB_multisample                  - добавлено 
             WGL_ARB_pixel_format                 - было
             WGL_EXT_extensions_string            - было
             WGL_EXT_swap_control                 - было
 
/////////////////////////////////////////////////////////////
// приложения
/////////////////////////////////////////////////////////////
1. learnig_var demo (nVidia)
2. winpos demo (MESA) 
3. RadeonAutoMipGen demo (ATI)
4. OpenGL Extensions Viewer v2.06.261 (Realtech VR)
