"""One-time WPF-to-Avalonia view migration preserving RC1 layout and named controls.
The resulting Avalonia view is the shared UI source; this is not a runtime translator.
"""
from pathlib import Path
import xml.etree.ElementTree as ET
import re,json,copy,hashlib
ROOT=Path(__file__).resolve().parents[2]
A='https://github.com/avaloniaui';X='http://schemas.microsoft.com/winfx/2006/xaml';L='using:Outbreak.Launcher.Desktop.Controls'
ET.register_namespace('',A);ET.register_namespace('x',X);ET.register_namespace('local',L)
def q(n):return '{'+A+'}'+n
def local(n):return n.rsplit('}',1)[-1]
def read(name):
 text=(ROOT/'launcher'/name).read_text(encoding='utf-8-sig').replace('http://schemas.microsoft.com/winfx/2006/xaml/presentation',A).replace('clr-namespace:Outbreak.Launcher',L)
 return ET.fromstring(text)
colors={'Background':'141210','Surface':'24211E','Text':'F3ECDF','TextMuted':'B3A898','Accent':'DB6A22','AccentDeep':'9A4008','Danger':'DB6A22','WarmIvory':'F3ECDF','WarmIvoryMuted':'B3A898','SoftBlack':'141210','SoftBlackRaised':'24211E','BurntOrange':'DB6A22','BurntOrangeDeep':'9A4008','ControlLine':'66F3ECDF'}
def palette(s):
 def replace(m):
  value=colors[m[1]];alpha=int(m[2] or '255');a=int(value[:2],16) if len(value)==8 else 255
  return '#'+f'{a*alpha//255:02X}'+value[-6:]
 return re.sub(r'\{local:Palette (\w+)(?:, Alpha=(\d+))?\}',replace,s)
styles=read('Theme.xaml');based={}
for node in styles:
 key=node.get('{'+X+'}Key');base=node.get('BasedOn','')
 if key and (m:=re.fullmatch(r'\{StaticResource (\w+)\}',base)):based[key]=m[1]
def classes(key):return ' '.join([key]+(classes(based[key]).split() if key in based else []))
removed=set();actions={}
events={'Click','Checked','Unchecked','SelectionChanged','ValueChanged','TextChanged','DropDownOpened','RequestBringIntoView','MouseLeftButtonDown','MouseLeftButtonUp','MouseMove','MouseWheel','MouseLeave','MouseEnter','PreviewKeyDown','KeyDown','Loaded','SizeChanged','LostKeyboardFocus','DragEnter','Drop'}
drop={'FocusVisualStyle','TextOptions.TextFormattingMode','TextOptions.TextRenderingMode','SnapsToDevicePixels','RenderOptions.BitmapScalingMode','AllowsTransparency','PopupAnimation','IsItemsHost','ViewportUnits','ViewboxUnits','Grid.IsSharedSizeScope','ScrollViewer.CanContentScroll','IsTextSearchEnabled','IsSynchronizedWithCurrentItem','IsReadOnlyCaretVisible','LoadedBehavior','UnloadedBehavior','IsMuted','Volume','ToolTipService.ShowOnDisabled','ListBox.HorizontalContentAlignment'}
rename={'Panel.ZIndex':'ZIndex','ToolTip':'ToolTip.Tip','Viewport':'DestinationRect','Viewbox':'SourceRect','Track.DecreaseRepeatButton':'Track.DecreaseButton','Track.IncreaseRepeatButton':'Track.IncreaseButton','TextBox.SelectionBrush':'TextBox.SelectionBrush'}
def convert(node):
 name=local(node.tag)
 if name in {'Grid.CacheMode','BitmapCache','Path.Effect','Ellipse.Effect','Rectangle.Effect','BlurEffect','ControlTemplate.Triggers','Style.Triggers','TextBlock.Style','TextBox.Resources'}:
  removed.add(name);return None
 if name=='MediaElement':node.tag='{'+L+'}VideoSurface'
 elif name=='StatusText':node.tag=q('TextBlock')
 elif name=='Geometry':node.tag=q('StreamGeometry')
 elif name in ('Track.DecreaseRepeatButton','Track.IncreaseRepeatButton'):node.tag=q(rename[name])
 elif name.endswith('.ToolTip'):node.tag=q('ToolTip.Tip')
 elif name=='ListBox.ItemContainerStyle':node.tag=q('ListBox.Styles')
 if name=='Style' and 'TargetType' in node.attrib:node.set('Selector',node.attrib.pop('TargetType'))
 if name=='ContentPresenter' and 'Content' not in node.attrib:
  node.set('Background','Transparent');node.set('Content','{TemplateBinding Content}');node.set('ContentTemplate','{TemplateBinding ContentTemplate}')
 if name=='StackPanel' and node.get('IsItemsHost')=='True':
  node.tag=q('ItemsPresenter');node.set('{'+X+'}Name','PART_ItemsPresenter');node.set('ItemsPanel','{TemplateBinding ItemsPanel}')
 if name=='ItemsPresenter':node.set('ItemsPanel','{TemplateBinding ItemsPanel}')
 if name=='ScrollViewer' and node.get('{'+X+'}Name')=='PART_ContentHost':
  node.set('{'+X+'}Name','PART_ScrollViewer')
  ET.SubElement(node,q('TextPresenter'),{'{'+X+'}Name':'PART_TextPresenter','Text':'{TemplateBinding Text, Mode=TwoWay}','CaretIndex':'{TemplateBinding CaretIndex}','SelectionStart':'{TemplateBinding SelectionStart}','SelectionEnd':'{TemplateBinding SelectionEnd}','TextWrapping':'{TemplateBinding TextWrapping}','Margin':'{TemplateBinding Padding}'})
 if name=='Setter':
  prop=node.get('Property','')
  if prop in drop:return None
  if prop=='Visibility':
   node.set('Property','Opacity' if node.get('Value')=='Hidden' else 'IsVisible');node.set('Value','0' if node.get('Value')=='Hidden' else str(node.get('Value')=='Visible').lower())
 for key,value in list(node.attrib.items()):
  if key in events:
   identity=node.get('{'+X+'}Name') or node.get('Name')
   if not identity:
    identity='Action_'+value+'_'+str(len(actions));node.set('{'+X+'}Name',identity)
   actions.setdefault(identity,{})[key]=value
   del node.attrib[key];continue
  if (name=='ListBox' and key=='HorizontalContentAlignment') or (name.endswith('Transform') and key=='{'+X+'}Name') or key in drop or key=='Icon' or (key=='Command' and 'x:Static' in value):del node.attrib[key];continue
  if key=='Visibility':
   del node.attrib[key]
   if value=='Hidden':node.set('Opacity','0');node.set('IsHitTestVisible','False')
   else:node.set('IsVisible',str(value=='Visible').lower())
   continue
  if key=='Style':
   del node.attrib[key]
   m=re.fullmatch(r'\{StaticResource ([\w]+)\}',value)
   if m:node.set('Classes',classes(m[1]))
   continue
  if key=='SelectedValuePath':del node.attrib[key];node.set('SelectedValueBinding','{Binding '+value+'}');continue
  if key=='DisplayMemberPath':del node.attrib[key];node.set('DisplayMemberBinding','{Binding '+value+'}');continue
  value=palette(value)
  value=re.sub(r'\{Binding (\w+), RelativeSource=\{RelativeSource AncestorType=(\w+)\}\}',r'{Binding $parent[\2].\1}',value)
  value=value.replace('ActualWidth','Bounds.Width').replace('ActualHeight','Bounds.Height')
  if key=='{'+X+'}Class':value='Outbreak.Launcher.Desktop.MainWindow'
  if key in rename:del node.attrib[key];key=rename[key]
  if name=='Setter' and key=='Property' and value=='ToolTip':value='ToolTip.Tip'
  if name=='TextBox' and key in ('VerticalScrollBarVisibility','HorizontalScrollBarVisibility'):del node.attrib[key];key='ScrollViewer.'+key
  if name=='Setter' and key=='Property' and value in ('VerticalScrollBarVisibility','HorizontalScrollBarVisibility'):value='ScrollViewer.'+value
  if key in ('StrokeStartLineCap','StrokeEndLineCap'):del node.attrib[key];key='StrokeLineCap'
  node.set(key,value)
 for child in list(node):
  new=convert(child)
  if new is None:node.remove(child)
 return node
shell=convert(read('Shell.xaml'))
shell.set('xmlns:local',L) if not any(n.tag.startswith('{'+L+'}') for n in shell.iter()) else None
out=ROOT/'launcher/desktop/Views'
ET.indent(shell);ET.ElementTree(shell).write(out/'Shell.axaml',encoding='unicode',xml_declaration=False)
# Preserve original control templates and translate state triggers to Avalonia selectors.
root=ET.Element(q('Styles'));resources=ET.SubElement(root,q('Styles.Resources'))
resource_dict=ET.SubElement(resources,q('ResourceDictionary'))
selectors={}
for source in styles:
 if local(source.tag)!='Style':
  resource_dict.append(convert(copy.deepcopy(source)));continue
 target=source.get('TargetType','');key=source.get('{'+X+'}Key')
 selector=target+('.'+key if key else '')
 selectors[key or target]=selector
 style=ET.SubElement(root,q('Style'),{'Selector':selector})
 for setter in source.findall(q('Setter')):
  new=convert(copy.deepcopy(setter))
  if new is not None:style.append(new)
 # Each named target stays in its original template; states become pseudo classes.
 names={n.get('{'+X+'}Name'):local(n.tag) for n in source.iter() if n.get('{'+X+'}Name')}
 for group in source.iter():
  if local(group.tag) not in ('ControlTemplate.Triggers','Style.Triggers'):continue
  for trigger in group:
   prop,value=trigger.get('Property',''),trigger.get('Value','')
   if local(trigger.tag)=='DataTrigger':
    if 'IsSelected' in trigger.get('Binding',''):
     state='';prefix='ListBoxItem:selected '+selector
    else:continue
   else:
    state={'IsMouseOver':':pointerover','IsKeyboardFocused':':focus-visible','IsKeyboardFocusWithin':':focus-within','IsEnabled':':disabled','IsChecked':':checked','IsSelected':':selected','IsHighlighted':':pointerover','local:InputFeedback.IsActive':'.input-active'}.get(prop)
    if state is None:continue
    if prop=='IsEnabled' and value!='False':continue
    if prop!='IsEnabled' and value=='False':state=':not('+state+')'
    prefix=selector+state
   for old in trigger.findall(q('Setter')):
    name=old.get('TargetName')
    childselector=prefix+(' /template/ '+names.get(name,'Control')+'#'+name if name else '')
    sub=ET.SubElement(root,q('Style'),{'Selector':childselector})
    new=copy.deepcopy(old);new.attrib.pop('TargetName',None);new=convert(new)
    if new is not None:sub.append(new)
# FontFamily XAML text needs an explicit fallback; owned game font replaces it at runtime.
ET.indent(root);ET.ElementTree(root).write(out/'Theme.axaml',encoding='unicode',xml_declaration=False)
metadata={'reference':'v1.0.20-rc1','sourceSha256':{n:hashlib.sha256((ROOT/'launcher'/n).read_bytes()).hexdigest() for n in ['Shell.xaml','Theme.xaml']},'actions':actions,'removedWpfMechanisms':sorted(removed),'styleClasses':based}
(out/'Shell.reference.json').write_text(json.dumps(metadata,indent=2))
print('Ported',len(list(shell.iter())),'view elements;',len(actions),'named event sources')
