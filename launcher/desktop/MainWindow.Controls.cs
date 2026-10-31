using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.Primitives;
using Avalonia.Input;
using Avalonia.Interactivity;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using System.Text.Json;
using Outbreak.Launcher.Desktop.Compatibility;
using Outbreak.Launcher.Desktop.Controls;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow {
    readonly Dictionary<string,Button> bindingButtons=[];
    PadProfile CurrentProfile=>controller.SelectedDevice.Kind=="playstation"?Settings.PlayStation:Settings.Xbox;
    Dictionary<string,int> CurrentBindings=>controller.SelectedDevice.Kind=="keyboard"?Settings.Keyboard:CurrentProfile.Buttons;
    string captureTarget="",deviceListKey="";
    HashSet<int> captureHeld=[];
    void BuildBindings()=>BuildBindingRows();
    Bitmap? LoadControllerBitmap(string import,string edition) {
        var bytes=GameControllerArtwork.LoadPixels(import,edition);
        return bytes==null?null:ArtworkLoader.FromBgra(bytes,GameControllerArtwork.Width,GameControllerArtwork.Height);
    }
    void BuildBindingRows() {
        bindingButtons.Clear();BindingRows.Children.Clear();
        if(BuildControllerMap())return;
        foreach(var action in InputMapping.Actions) {
            var row=new Grid{Margin=new Thickness(0,4,14,4),ColumnDefinitions=new("*,115,48")};
            row.Children.Add(new TextBlock{Text=action.Label,VerticalAlignment=VerticalAlignment.Center});
            var binding=new Button{Content=InputMapping.SourceName(CurrentBindings.GetValueOrDefault(action.Id),controller.SelectedDevice.Kind),Tag=action.Id,Padding=new Thickness(12,7)};
            binding.Click+=StartBinding;bindingButtons[action.Id]=binding;Grid.SetColumn(binding,1);row.Children.Add(binding);
            var clear=new Button{Content="Clear",Margin=new Thickness(7,0,0,0),Padding=new Thickness(6),FontSize=11};
            clear.Click+=(_,_)=>ClearBinding(action.Id);Grid.SetColumn(clear,2);row.Children.Add(clear);BindingRows.Children.Add(row);
        }
    }
    void UpdateInput() {
        string key=string.Join('|',controller.AvailableDevices.Select(d=>d.Id));
        if(key!=deviceListKey){deviceListKey=key;InputDevicePicker.ItemsSource=controller.AvailableDevices;InputDevicePicker.SelectedItem=controller.SelectedDevice;BuildBindings();}
        ControllerDetail.Text=controller.SelectedDevice.Available?controller.SelectedDevice.Name:"Selected device is unavailable. Connect it or choose another.";
        DeadZoneLabel.Text=$"Dead zone: {CurrentProfile.DeadZone}%";
        LeftPlot.Pad=RightPlot.Pad=controller.State;LeftPlot.Right=false;RightPlot.Right=true;
        LeftPlot.DeadZone=RightPlot.DeadZone=CurrentProfile.DeadZone;LeftPlot.InvalidateVisual();RightPlot.InvalidateVisual();
        foreach(var (action,button) in bindingButtons)button.Classes.Set("input-active",captureTarget.Length==0&&InputMapping.ActionPressed(controller.State,action));
        if(captureTarget.Length>0&&controller.SelectedDevice.Kind!="keyboard") {
            var pressed=InputMapping.Pressed(controller.RawState);
            int fresh=pressed.Except(captureHeld).FirstOrDefault();
            if(fresh!=0)FinishBinding(fresh);
            captureHeld=pressed;
        }
    }
    void StartBinding(object? sender,RoutedEventArgs e) {
        if(sender is not Button {Tag:string action})return;
        captureTarget=action;captureHeld=InputMapping.Pressed(controller.RawState);
        CaptureHint.Text="Press a key or controller button for "+action+". Escape cancels.";
        CapturePanel.IsVisible=true;
    }
    void FinishBinding(int code){CurrentBindings[captureTarget]=code;CancelCapture(this,new());SaveInputPreferences();BuildBindingRows();}
    void CancelCapture(object? sender,RoutedEventArgs e){captureTarget="";CapturePanel.IsVisible=false;}
    void SaveInputPreferences(){controller.Configure(Settings);Changed();}
    void ResetBindings() {
        if(controller.SelectedDevice.Kind=="keyboard")Settings.Keyboard=InputMapping.KeyboardDefaults();
        else CurrentProfile.Buttons=InputMapping.PadDefaults();
        SaveInputPreferences();BuildBindings();
    }
    void CaptureKey(KeyEventArgs e,bool down) {
        int code=VirtualKey(e.Key);
        if(code!=0)NativeControllers.SetKey(code,down);
        if(!down||captureTarget.Length==0||controller.SelectedDevice.Kind!="keyboard")return;
        if(e.Key==Key.Escape)CancelCapture(this,new());else if(code!=0)FinishBinding(code);
        e.Handled=true;
    }
    internal static int VirtualKey(Key key) {
        string name=key.ToString();
        if(name.Length==1&&char.IsAsciiLetterUpper(name[0]))return name[0];
        if(name.Length==2&&name[0]=='D'&&char.IsDigit(name[1]))return name[1];
        if(name.StartsWith('F')&&int.TryParse(name[1..],out int f)&&f is >=1 and <=12)return 111+f;
        return key switch{Key.Space=>32,Key.Enter=>13,Key.Back=>8,Key.Tab=>9,Key.Escape=>27,Key.Left=>37,Key.Up=>38,Key.Right=>39,Key.Down=>40,Key.OemSemicolon=>186,Key.OemPlus=>187,Key.OemComma=>188,Key.OemMinus=>189,Key.OemPeriod=>190,Key.OemQuestion=>191,Key.OemTilde=>192,Key.OemOpenBrackets=>219,Key.OemPipe=>220,Key.OemCloseBrackets=>221,Key.OemQuotes=>222,_=>0};
    }
}
