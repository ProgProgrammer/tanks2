# Tanks 2

## Описание игры

Копия известной игры на Sega - Battle City.

![image-20220910200930378](images/image-20220910200930378.png)

## Возможности

- Уровень загружается из текстового файла [levels.txt](./levels.txt), который можно легко редактировать.
- Танк передвигается на стрелочки.
- Работа с коллизиями на местности не реализована.

## Диаграмма классов (UML)

[TankUML.drawio](./TankUML.drawio)

![image-20220907171559325](images/image-20220907171559325.png)

## To Do list

- Танк.
  - Коллизии со стенами.
  - Танк стреляет.
  - Танк может управляться ботом, может человеком.
  - Звуки взрыва и выстрела.
  - Взрыв танка меняет его цвет и он исчезает.
- Инсталлятор игры.

## Deploy

```
vcpkg install sfml
vcpkg integrate project
Install-Package vcpkg.C.dev.vcpkg -Source "C:\dev\vcpkg\scripts\buildsystems"
```

