"""Initial migration of RC1's code-built rows; preserve its actual layout code."""
from pathlib import Path
import re
root=Path(__file__).resolve().parents[2]
for name in ['Mods','Cheats','ControllerMap']:
 source=(root/f'launcher/MainWindow.{name}.cs').read_text()
 source=re.sub(r'^using (?:System.Windows[^;]*|Microsoft.Win32);\n','',source,flags=re.M)
 source='''using Avalonia;
using Avalonia.Layout;
using Path = System.IO.Path;
using Avalonia.Controls;
using Avalonia.Controls.Shapes;
using Avalonia.Controls.Primitives;
using Avalonia.Automation;
using Avalonia.Input;
using Avalonia.Interactivity;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Outbreak.Launcher.Desktop.Compatibility;
using BitmapSource = Avalonia.Media.Imaging.Bitmap;
using PointCollection = Avalonia.Points;
'''+source
 source=source.replace('namespace Outbreak.Launcher;','namespace Outbreak.Launcher.Desktop;')
 source=re.sub(r'\bsettings\b','Settings',source);source=re.sub(r'\broot\b','Root',source)
 for key in ['launching','updating','updateRestarting','backingUp']:source=re.sub(r'\b'+key+r'\b','busy',source)
 source=re.sub(r'(?<![.\w])ActualHeight', 'Bounds.Height', source)
 source=re.sub(r'(?<![.\w])ActualWidth', 'Bounds.Width', source)
 source=re.sub(r'(?<![.\w])IsLoaded', 'IsVisible', source)
 source=source.replace('RenderOptions.SetBitmapScalingMode(diagramImage, BitmapScalingMode.HighQuality);','RenderOptions.SetBitmapInterpolationMode(diagramImage, BitmapInterpolationMode.HighQuality);')
 source=source.replace('Palette.Brush(', 'VisualPalette.Brush(').replace('System.Windows.', 'Avalonia.')
 source=re.sub(r'(\w+)\.Unchecked \+= (\w+);','',source)
 source=source.replace('.Checked +=','.IsCheckedChanged +=')
 source=source.replace('dialog.ShowDialog(this)','await dialog.ShowDialog(this)')
 source=source.replace('    void ImportCheats(', '    async void ImportCheats(')
 source=source.replace('GameControllerArtwork.Load(import, edition, Settings.Home)','LoadControllerBitmap(import, edition)')
 source=source.replace('Style = (Style)FindResource(', 'Style = (Compatibility.Style)FindResource(')
 source=source.replace('    void ControllerDiagramSizeChanged(object sender, SizeChangedEventArgs e)', '    void ControllerDiagramSizeChanged(object? sender, SizeChangedEventArgs e)')
 (root/f'launcher/desktop/MainWindow.{name}.cs').write_text(source)
