# GameSDL_CPP_knife_hit_fake

- Game một phần dựa trên trò chơi Knife Hit gốc
- Mã nguồn được viết bằng ngôn ngữ C++ đồ hoạ SDL 2.0.14

CÁC ĐỐI TƯỢNG TRONG GAME:

- Một vật cản hình vuông gọi là Block
- Dao

HƯỚNG DẪN CHƠI:

- Đối tượng dao di chuyển qua lại theo trục X
- Click chuột trái để phi dao
- Mỗi lần dao găm vào Block được tính là 100 điểm
- Nếu dao được phi mà không găm vào Block thì Gameover
- Tốc độ di chuyển qua lại của dao sẽ tăng dần theo thời gian

Ý TƯỞNG:

-Ý tưởng từ
https://www.youtube.com/watch?v=JnF91uaG81k&t=369s

THƯ VIỆN:

- SDL_image
- SDL_tff
