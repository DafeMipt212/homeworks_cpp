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
5. Копируем публичный ключ (он лежит в файле с расширением .pub) в буффер обмена, и скидываем его [мне в телеграмм](https://tttttt.me/lostpointer). Содержание файла можно вывести командой ```cat (имя_файла).pub```
  
# 
