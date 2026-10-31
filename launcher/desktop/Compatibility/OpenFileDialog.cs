using Avalonia.Controls;
using Avalonia.Platform.Storage;

namespace Outbreak.Launcher.Desktop.Compatibility;

internal sealed class OpenFileDialog {
    public string Filter{get;set;}="";
    public bool Multiselect{get;set;}
    public string FileName=>FileNames.FirstOrDefault()??"";
    public string[] FileNames{get;private set;}=[];
    public async Task<bool?> ShowDialog(Window owner) {
        string[] parts=Filter.Split('|');var types=new List<FilePickerFileType>();
        for(int i=0;i+1<parts.Length;i+=2)types.Add(new(parts[i]){Patterns=parts[i+1].Split(';')});
        var selected=await owner.StorageProvider.OpenFilePickerAsync(new(){AllowMultiple=Multiselect,FileTypeFilter=types,Title="Choose file"});
        FileNames=selected.Select(p=>p.TryGetLocalPath()).Where(p=>p!=null).Cast<string>().ToArray();
        return FileNames.Length>0;
    }
}
