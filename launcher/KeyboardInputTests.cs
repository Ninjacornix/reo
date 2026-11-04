using System.Text.Json;

namespace Outbreak.Launcher;

internal static class KeyboardInputTests {
    internal static void Run(Action<bool,string> check) {
        var bindings=InputMapping.KeyboardDefaults();
        Pad Keys(params int[] keys)=>InputMapping.Keyboard(bindings,keys.Contains);
        foreach (var (key,button) in new (int,ushort)[]{('W',1),('S',2),('A',4),('D',8)}) {
            var pad=Keys(key);
            check(pad==new Pad(button),"keyboard D-pad sends only its digital button: "+(char)key);
        }
        check(Keys('W','D')==new Pad(9)&&Keys('S','A')==new Pad(6),"keyboard diagonals keep the left stick neutral");
        check(Keys('W','S')==new Pad()&&Keys('A','D')==new Pad()&&Keys('W','S','A','D')==new Pad(),"opposite digital directions cancel");
        foreach (var (key,x,y) in new (int,short,short)[]{(38,0,32767),(40,0,-32768),(37,-32768,0),(39,32767,0)})
            check(Keys(key)==new Pad(RX:x,RY:y),"right-stick key is independent from movement: "+key);
        check(Keys(37,39,38,40)==new Pad(),"opposite right-stick directions cancel");
        check(Keys('W',38)==new Pad(1,RY:32767),"distinct movement and voice keys can be pressed together");
        check(Keys('3','4',32)==new Pad(0x1000,255,255),"keyboard triggers and face buttons remain unchanged");
        foreach (var (action,key,button) in new (string,int,ushort)[]{("Up",38,1),("Down",40,2),("Left",37,4),("Right",39,8)}) {
            var cleared=InputMapping.BindKeyboard(bindings,action,key);
            check(cleared.Length==1&&cleared[0].StartsWith("Camera")&&Keys(key)==new Pad(button),"remapping arrows to D-pad clears the previous voice binding: "+action);
        }
        check(Keys('W','S','A','D')==new Pad(),"previous WASD bindings stop producing movement after remap");
        var saved=JsonSerializer.Deserialize<Dictionary<string,int>>(JsonSerializer.Serialize(bindings))!;
        check(InputMapping.Keyboard(saved,key=>key==38)==new Pad(1),"saved arrow remap retains digital movement without voice commands");
        check(InputMapping.BindKeyboard(bindings,"Up",38).Length==0&&Keys(38)==new Pad(1),"recapturing the current key keeps its binding");
        InputMapping.BindKeyboard(bindings,"CameraUp",38);
        check(bindings["Up"]==0&&Keys(38)==new Pad(RY:32767),"remapping back to right stick releases conflicting D-pad input");
        InputMapping.BindKeyboard(bindings,"CameraUp",0);
        check(Keys(38)==new Pad(),"clearing a voice binding releases its right-stick input");
        check(Keys()==new Pad(),"key release clears all keyboard input");
        bindings["Start"]=13;
        check(Keys(13,17)==new Pad()&&Keys(13,162)==new Pad()&&Keys(13,163)==new Pad(),"fullscreen chord cannot press Start");
        string before=JsonSerializer.Serialize(bindings);
        foreach (int invalid in new[]{-1,256}) {
            bool rejected=false;try{InputMapping.BindKeyboard(bindings,"Up",invalid);}catch(ArgumentOutOfRangeException){rejected=true;}
            check(rejected&&JsonSerializer.Serialize(bindings)==before,"invalid virtual key cannot change saved bindings");
        }
        bool unknown=false;try{InputMapping.BindKeyboard(bindings,"not-an-action",65);}catch(ArgumentException){unknown=true;}
        check(unknown&&JsonSerializer.Serialize(bindings)==before,"unknown action cannot change saved bindings");
    }
}
