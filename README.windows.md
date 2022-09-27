# Устанавливака Git
1. Переходим по одной из ссылок [64bit](https://github.com/git-for-windows/git/releases/download/v2.37.3.windows.1/Git-2.37.3-64-bit.exe) [32bit](https://github.com/git-for-windows/git/releases/download/v2.37.3.windows.1/Git-2.37.3-32-bit.exe)
2. Устанавливаем, на 3х картинках важные пункты которые нужно будет выбрать (они могут быть установлены по умолчанию)
    <img width="240" alt="git-setup-0" src="https://user-images.githubusercontent.com/3163640/192623637-43eedfbf-a3ae-4ad6-bf09-c11d87db78fb.png">
    <img width="358" alt="git-setup-1" src="https://user-images.githubusercontent.com/3163640/192623676-39cab809-5f34-4195-a9ff-6b3171b734d2.png">
    <img width="356" alt="git-setup-3" src="https://user-images.githubusercontent.com/3163640/192623690-1d97730c-1379-45c4-b1f5-dc2b83b5ac80.png">
3. Перезагружаем систему

# Генерируем ключи для получения доступа к виртуальной машине
1. Запускаем Git Bash
2. Вводим команду ```mkdir -p ~/.ssh && cd ~/.ssh``` (создание папки .ssh и переход в нее)
3. Проверяем что ключей ещё нет, если есть как минимум 2 файла с одинаковым именем один без разрешения второй с расширением .pub, то сразу переходим к пункту 5
4. Генерируем ssh ключи для доступа к гиту и виртуальной машине 
    ```ssh-keygen -t ed25519 -C "your_email@example.com"```
    Когда увидим сообщение "Enter file in which to save the key (/c/Users/lostp/.ssh/id_ed25519):" нажимаем Enter.
    Потом ещё 2 раза Enter на строчках "Enter passphrase (empty for no passphrase):" и "Enter same passphrase again:"
5. Копируем публичный ключ (он лежит в файле с расширением .pub) в буффер обмена, и скидываем его [мне в телеграмм](https://tttttt.me/lostpointer). Содержание файла можно вывести командой ```cat (имя_файла).pub```. Вашим логином в виртуальной машине сдеалю ваш логин в телеграмме
  
# Установка VSCode
1. Устанавливаем VSCode
2. Устанавливаем расширения:
    1. C/C++ Extension Pack
    2. CMake Tools
    3. Remote - SSH
    4. Remote - SSH: Editing Configuration Files
    5. Remote Development
3. Запускаем VSCode и жмем на значек ![Удаленного обозревателя](https://user-images.githubusercontent.com/3163640/192628642-ae408c12-218a-4c5a-b7ef-c75a98b205de.png)
4. Создаем подключение в виртуальной машине ![2022-09-27_23-29-45](https://user-images.githubusercontent.com/3163640/192629474-c408edca-92de-441e-9d57-6f00db492bcd.png)
5. Вбиваем ваш_логин_в_телеграмм@51.250.79.107 ![2022-09-27_23-33-56](https://user-images.githubusercontent.com/3163640/192630730-6446b248-d751-490e-ad4c-27d70af5b49c.png)
6. Следующим шагом выбираем Linux (т.к. на виртуальной машине стоит именно он). В следующем пункте нажимаем Продолжить
7. Для того что бы убедится что все работает набираем в терминале whoami и видим свой логин

# Работа с репозиторием
TODO
