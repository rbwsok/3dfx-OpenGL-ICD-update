# 3dfx-OpenGL-ICD-update (build 12)

[Archive] 3dfx OpenGL ICD update

Откопано в старых архивах 2006 года!!!

Исходник - лютый треш. Особо впечатлительным просьба не открывать.

Оставлено для истории и особо упоротых фанатов.

Данная dll встает между стандартным OpenGL драйвером и приложением. И перехватывает часть функций OpenGL.
Добавляет поддержку ряда OpenGL расширений (VBO и т.д.). Также имеет некоторые эксперементальные функции,
типа автоматической компрессии всех текстур (Voodoo4/5), форсирование разрешения для первичного видеоадаптера (Voodoo2)
и т.д.

Работает только c 
ICD v1.0.0.0508 от 27 января 2000г - для Voodoo2 и
ICD v1.0.0.0761 от 16 января 2001г - для Banshee/3/4/5

Собиралось в MSVC6.
