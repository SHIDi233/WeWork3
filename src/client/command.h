/**
* 用于存储一些枚举类
*/

#ifndef COMMAND_H
#define COMMAND_H

enum E_COLOR {//气泡颜色
    eWechatGreen,
    eWhite
};

enum E_WHOSAY {//说话主体
    eMe,
    eFriend
};

enum F_TYPE {//文件类型
    fPic,
    fVideo,
    fFile
};
//#define WECHATGREEN 152, 225, 101
#define WECHATGREEN 0, 170, 255
#define WHITE 255,255,255

#endif // COMMAND_H
