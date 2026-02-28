#ifndef __WEBSOCKET_CLIENT_H__
#define __WEBSOCKET_CLIENT_H__

 #include <string>

// Define the callback function type
typedef void (*ws_recv_callback_t)(const char *buffer, size_t size);

// WebSocket event callback type (on_connected / on_disconnected)
typedef void (*ws_event_callback_t)(void* user_data);

typedef struct websocket_data_t {
    std::string hostname;
    std::string port;
    std::string path; 
    std::string hello;
    std::string headers;
} websocket_data_t;

/**
 * 发送二进制数据
 * 
 * @param data 数据指针
 * @param size 数据大小
 * @return 错误码
 */
int websocket_send_binary(const char *data, int size);

/**
 * 发送文本数据
 * 
 * @param data 数据指针
 * @param size 数据大小
 * @return 错误码
 */
int websocket_send_text(const char *data, int size) ;
/**
 * 设置回调函数和数据
 * 
 * @param bin_cb 二进制数据接收回调
 * @param txt_cb 文本数据接收回调
 * @param ws_data WebSocket数据
 * @return 返回值
 */
int websocket_set_callbacks(ws_recv_callback_t bin_cb, ws_recv_callback_t txt_cb, websocket_data_t *ws_data);

/**
 * 设置WebSocket事件回调（连接/断开）
 *
 * @param on_connected 连接成功回调（可为nullptr）
 * @param on_disconnected 连接断开回调（可为nullptr）
 * @param user_data 传递给回调的用户数据
 * @return 返回值
 */
int websocket_set_event_callbacks(ws_event_callback_t on_connected, ws_event_callback_t on_disconnected, void* user_data);

/**
 * 启动WebSocket线程
 *
 * @return 返回值
 */
int websocket_start() ;

#endif