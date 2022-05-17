#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

const char* ssid = "SSID";
const char* pwd = "PASSWORD"; //has to be greater than 8 characters

String website = "<!DOCTYPE html><html lang=en><head><meta charset=UTF-8><meta http-equiv=X-UA-Compatible content=\"IE=edge\"><meta name=viewport content=\"width=device-width, initial-scale=1.0\"><style>*,::after,::before{box-sizing:border-box;border-width:0;border-style:solid;border-color:currentColor}::after,::before{--tw-content:''}html{line-height:1.5;-webkit-text-size-adjust:100%;-moz-tab-size:4;-o-tab-size:4;tab-size:4;font-family:ui-sans-serif,system-ui,-apple-system,BlinkMacSystemFont,\"Segoe UI\",Roboto,\"Helvetica Neue\",Arial,\"Noto Sans\",sans-serif,\"Apple Color Emoji\",\"Segoe UI Emoji\",\"Segoe UI Symbol\",\"Noto Color Emoji\"}body{margin:0;line-height:inherit}hr{height:0;color:inherit;border-top-width:1px}abbr:where([title]){-webkit-text-decoration:underline dotted;text-decoration:underline dotted}h1,h2,h3,h4,h5,h6{font-size:inherit;font-weight:inherit}a{color:inherit;text-decoration:inherit}b,strong{font-weight:bolder}code,kbd,pre,samp{font-family:ui-monospace,SFMono-Regular,Menlo,Monaco,Consolas,\"Liberation Mono\",\"Courier New\",monospace;font-size:1em}small{font-size:80%}sub,sup{font-size:75%;line-height:0;position:relative;vertical-align:baseline}sub{bottom:-.25em}sup{top:-.5em}table{text-indent:0;border-color:inherit;border-collapse:collapse}button,input,optgroup,select,textarea{font-family:inherit;font-size:100%;line-height:inherit;color:inherit;margin:0;padding:0}button,select{text-transform:none}[type=button],[type=reset],[type=submit],button{-webkit-appearance:button;background-color:transparent;background-image:none}:-moz-focusring{outline:auto}:-moz-ui-invalid{box-shadow:none}progress{vertical-align:baseline}::-webkit-inner-spin-button,::-webkit-outer-spin-button{height:auto}[type=search]{-webkit-appearance:textfield;outline-offset:-2px}::-webkit-search-decoration{-webkit-appearance:none}::-webkit-file-upload-button{-webkit-appearance:button;font:inherit}summary{display:list-item}blockquote,dd,dl,figure,h1,h2,h3,h4,h5,h6,hr,p,pre{margin:0}fieldset{margin:0;padding:0}legend{padding:0}menu,ol,ul{list-style:none;margin:0;padding:0}textarea{resize:vertical}input::-moz-placeholder,textarea::-moz-placeholder{opacity:1;color:#9ca3af}input:-ms-input-placeholder,textarea:-ms-input-placeholder{opacity:1;color:#9ca3af}input::placeholder,textarea::placeholder{opacity:1;color:#9ca3af}[role=button],button{cursor:pointer}:disabled{cursor:default}audio,canvas,embed,iframe,img,object,svg,video{display:block;vertical-align:middle}img,video{max-width:100%;height:auto}[hidden]{display:none}*,::after,::before{--tw-translate-x:0;--tw-translate-y:0;--tw-rotate:0;--tw-skew-x:0;--tw-skew-y:0;--tw-scale-x:1;--tw-scale-y:1;--tw-pan-x:;--tw-pan-y:;--tw-pinch-zoom:;--tw-scroll-snap-strictness:proximity;--tw-ordinal:;--tw-slashed-zero:;--tw-numeric-figure:;--tw-numeric-spacing:;--tw-numeric-fraction:;--tw-ring-inset:;--tw-ring-offset-width:0;--tw-ring-offset-color:#fff;--tw-ring-color:rgb(59 130 246 / .5);--tw-ring-offset-shadow:0 0 #0000;--tw-ring-shadow:0 0 #0000;--tw-shadow:0 0 #0000;--tw-shadow-colored:0 0 #0000;--tw-blur:;--tw-brightness:;--tw-contrast:;--tw-grayscale:;--tw-hue-rotate:;--tw-invert:;--tw-saturate:;--tw-sepia:;--tw-drop-shadow:;--tw-backdrop-blur:;--tw-backdrop-brightness:;--tw-backdrop-contrast:;--tw-backdrop-grayscale:;--tw-backdrop-hue-rotate:;--tw-backdrop-invert:;--tw-backdrop-opacity:;--tw-backdrop-saturate:;--tw-backdrop-sepia:}.container{width:100%}@media(min-width:640px){.container{max-width:640px}}@media(min-width:768px){.container{max-width:768px}}@media(min-width:1024px){.container{max-width:1024px}}@media(min-width:1280px){.container{max-width:1280px}}@media(min-width:1536px){.container{max-width:1536px}}.m-1{margin:.25rem}.mx-auto{margin-left:auto;margin-right:auto}.mx-1{margin-left:.25rem;margin-right:.25rem}.mx-2{margin-left:.5rem;margin-right:.5rem}.h-72{height:18rem}.h-5{height:1.25rem}.h-20{height:5rem}.h-14{height:3.5rem}.h-28{height:7rem}.w-72{width:18rem}.w-full{width:100%}.w-28{width:7rem}.select-none{-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none}.rounded-full{border-radius:9999px}.rounded-b-3xl{border-bottom-right-radius:1.5rem;border-bottom-left-radius:1.5rem}.bg-dgre{--tw-bg-opacity:1;background-color:rgb(31 31 31 / var(--tw-bg-opacity))}.bg-gre{--tw-bg-opacity:1;background-color:rgb(51 56 63 / var(--tw-bg-opacity))}.bg-grn{--tw-bg-opacity:1;background-color:rgb(197 238 208 / var(--tw-bg-opacity))}.bg-blu{--tw-bg-opacity:1;background-color:rgb(97 179 238 / var(--tw-bg-opacity))}.bg-mgre{--tw-bg-opacity:1;background-color:rgb(40 42 45 / var(--tw-bg-opacity))}.bg-lblu{--tw-bg-opacity:1;background-color:rgb(212 227 252 / var(--tw-bg-opacity))}.py-28{padding-top:7rem;padding-bottom:7rem}.text-right{text-align:right}.text-8xl{font-size:6rem;line-height:1}.text-4xl{font-size:2.25rem;line-height:2.5rem}.text-5xl{font-size:3rem;line-height:1}.text-wt{--tw-text-opacity:1;color:rgb(255 255 255 / var(--tw-text-opacity))}.text-blk{--tw-text-opacity:1;color:rgb(0 0 0 / var(--tw-text-opacity))}.caret-crsr{caret-color:#99b2df}.transition{transition-property:color,background-color,border-color,fill,stroke,opacity,box-shadow,transform,filter,-webkit-text-decoration-color,-webkit-backdrop-filter;transition-property:color,background-color,border-color,text-decoration-color,fill,stroke,opacity,box-shadow,transform,filter,backdrop-filter;transition-property:color,background-color,border-color,text-decoration-color,fill,stroke,opacity,box-shadow,transform,filter,backdrop-filter,-webkit-text-decoration-color,-webkit-backdrop-filter;transition-timing-function:cubic-bezier(0.4,0,0.2,1);transition-duration:150ms}.delay-75{transition-delay:75ms}.delay-150{transition-delay:150ms}.duration-150{transition-duration:150ms}.ease-in{transition-timing-function:cubic-bezier(0.4,0,1,1)}.w-72{width:31.75rem}.h-b{height:8rem}.h-82{height:21rem}a,button,input,select,textarea{-webkit-tap-highlight-color:transparent}.active\:rounded-3xl:active{border-radius:1.5rem}.active\:bg-pgre1:active{--tw-bg-opacity:1;background-color:rgb(76 76 76 / var(--tw-bg-opacity))}.active\:bg-pgrn:active{--tw-bg-opacity:1;background-color:rgb(209 241 217 / var(--tw-bg-opacity))}.active\:bg-pblu:active{--tw-bg-opacity:1;background-color:rgb(128 194 241 / var(--tw-bg-opacity))}.active\:bg-pgre2:active{--tw-bg-opacity:1;background-color:rgb(83 85 87 / var(--tw-bg-opacity))}.active\:bg-plblu:active{--tw-bg-opacity:1;background-color:rgb(221 233 252 / var(--tw-bg-opacity))}</style><title>Calculator</title></head><body class=bg-dgre><div class=\"container mx-auto w-72\"><div class=\"mx-auto w-72\"><div class=\"bg-gre rounded-b-3xl h-82 w-72\"><textarea id=screen class=\"bg-gre text-wt text-8xl text-right h-72 py-28 w-full caret-crsr select-none\" readonly></textarea></div></div><div class=\"container select-none mx-auto w-72\"><div class=mx-2><div class=h-5></div><div class=h-20><button onclick=\"append('√')\" class=\"text-wt text-4xl h-14 m-1 w-28 rounded-full transition ease-in delay-75 active:bg-pgre1 active:rounded-3xl duration-150\">√</button><button onclick=\"append('π')\" class=\"text-wt text-4xl h-14 m-1 w-28 rounded-full transition ease-in delay-75 active:bg-pgre1 active:rounded-3xl duration-150\">π</button><button onclick=\"append('^')\" class=\"text-wt text-4xl h-14 m-1 w-28 rounded-full transition ease-in delay-75 active:bg-pgre1 active:rounded-3xl duration-150\">^</button><button onclick=\"append('!')\" class=\"text-wt text-4xl h-14 m-1 w-28 rounded-full transition ease-in delay-75 active:bg-pgre1 active:rounded-3xl duration-150\">!</button></div><div class=h-b><button onclick=ac() class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-grn transition ease-in delay-150 active:bg-pgrn active:rounded-3xl duration-150\">AC</button><button onclick=br() class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-blu transition ease-in delay-150 active:bg-pblu active:rounded-3xl duration-150\">( )</button><button onclick=\"append('%')\" class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-blu transition ease-in delay-150 active:bg-pblu active:rounded-3xl duration-150\">%</button><button onclick=\"append('÷')\" class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-blu transition ease-in delay-150 active:bg-pblu active:rounded-3xl duration-150\">÷</button></div><div class=h-b><button onclick=\"append('7')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">7</button><button onclick=\"append('8')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">8</button><button onclick=\"append('9')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">9</button><button onclick=\"append('×')\" class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-blu transition ease-in delay-150 active:bg-pblu active:rounded-3xl duration-150\">×</button></div><div class=h-b><button onclick=\"append('4')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">4</button><button onclick=\"append('5')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">5</button><button onclick=\"append('6')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">6</button><button onclick=\"append('-')\" class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-blu transition ease-in delay-150 active:bg-pblu active:rounded-3xl duration-150\">-</button></div><div class=h-b><button onclick=\"append('1')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">1</button><button onclick=\"append('2')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">2</button><button onclick=\"append('3')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">3</button><button onclick=\"append('+')\" class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-blu transition ease-in delay-150 active:bg-pblu active:rounded-3xl duration-150\">+</button></div><div class=h-b><button onclick=\"append('0')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">0</button><button onclick=\"append('.')\" class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">.</button><button onclick=del() class=\"text-wt text-5xl h-28 m-1 w-28 rounded-full bg-mgre transition ease-in delay-150 active:bg-pgre2 active:rounded-3xl duration-150\">⌫</button><button onclick=eq() class=\"text-blk text-5xl h-28 m-1 w-28 rounded-full bg-lblu transition ease-in delay-150 active:bg-plblu active:rounded-3xl duration-150\">=</button></div></div></div></div><script>var flag=false;var Socket;var d;function init(){Socket=new WebSocket(\"ws://\"+window.location.hostname+\":81/\");Socket.onmessage=function(a){processCommand(a)}}function processCommand(a){d=a.data}function append(b){var a=document.getElementById(\"screen\").innerHTML;document.getElementById(\"screen\").innerHTML=a+b}function del(){var a=document.getElementById(\"screen\").innerHTML;document.getElementById(\"screen\").innerHTML=document.getElementById(\"screen\").innerHTML.slice(0,a.length-1)}function ac(){document.getElementById(\"screen\").innerHTML=\"\";flag=false}function br(){if(flag==false){append(\"(\");flag=true}else{append(\")\");flag=false}}function precisionRoundMod(c,a){var b=Math.pow(10,a);var e=a<0?c:0.01/b+c;return Math.round(e*b)/b}function eq(){if(d.length>5){document.getElementById(\"screen\").innerHTML=d}else{var v=document.getElementById(\"screen\").value;v=v.replace(/×/g,\"*\");v=v.replace(/÷/g,\"/\");v=v.replace(/π/g,\"3.14159265\");if(v){v=eval(v);v=precisionRoundMod(parseFloat(v),10);document.getElementById(\"screen\").innerHTML=v}else{document.getElementById(\"screen\").innerHTML=\"Format error\"}}}window.onload=function(a){init()};</script></body></html>";

int interval = 500;                                  //send data to the client every 500ms (.5sec)
unsigned long previousMillis = 0;

WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

void setup() {
  Serial.begin(115200);
  pinMode(15,INPUT_PULLDOWN);           
 
  WiFi.softAP(ssid,pwd);
 
  Serial.print("Connected to network with IP address: ");
  Serial.println(WiFi.softAPIP());
  
  server.on("/", []() {
    server.send(200, "text\html", website);
  });
  server.begin();
  
  webSocket.begin();
}

void loop() {
  server.handleClient();
  webSocket.loop();
  
  unsigned long now = millis();
  if ((unsigned long)(now - previousMillis) >= interval) {
    int button = digitalRead(15);
    if(button==HIGH){
    webSocket.broadcastTXT("9995216745"); //enter your phone number here
    }
    else{
      webSocket.broadcastTXT("");
    }
    previousMillis = now;
  }
}
