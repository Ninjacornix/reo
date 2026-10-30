using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Outbreak.Launcher;

// Every brush the theme defines or its control templates draw must come from Palette.
static class PaletteTests {
    public static void Run(Action<bool, string> check) {
        check(Palette.All.Count == 6 && !Palette.Contains(Color.FromRgb(0xBD, 0x66, 0x65)),
              "Palette holds six colours: two soft blacks, two ivories, two burnt oranges");
        // Text and error text need 4.5:1 and control outlines and focus 3:1 on the background and
        // on surfaces (WCAG AA). Filled buttons carry ivory text.
        bool contrast = true;
        foreach (var back in new[] { Palette.Background, Palette.Surface }) {
            contrast &= Palette.Contrast(Palette.Text, back) >= 4.5 && Palette.Contrast(Palette.TextMuted, back) >= 4.5 &&
                        Palette.Contrast(Palette.Danger, back) >= 4.5 && Palette.Contrast(Palette.Accent, back) >= 3 &&
                        Palette.Contrast(Palette.ControlLine, back) >= 3;
        }
        check(contrast && Palette.Contrast(Palette.Text, Palette.AccentDeep) >= 4.5,
              "Palette text, error text, outlines and filled buttons stay readable");
        var resources = Application.Current?.Resources;
        if (resources == null)
            return;
        var stray = new List<string>();
        void Brush(object? value, string where) {
            switch (value) {
                case SolidColorBrush solid when solid.Color.A != 0 && !Palette.Contains(solid.Color):
                    stray.Add($"{where}: {solid.Color}");
                    break;
                case GradientBrush gradient:
                    foreach (var stop in gradient.GradientStops)
                        if (stop.Color.A != 0 && !Palette.Contains(stop.Color))
                            stray.Add($"{where}: gradient {stop.Color}");
                    break;
            }
        }
        void Setters(IEnumerable<SetterBase> setters, string where) {
            foreach (var setter in setters.OfType<Setter>())
                Brush(setter.Value, where + "." + setter.Property.Name);
        }
        void Tree(DependencyObject element, string where) {
            var local = element.GetLocalValueEnumerator();
            while (local.MoveNext())
                Brush(local.Current.Value, where + "/" + element.GetType().Name + "." + local.Current.Property.Name);
            for (int i = 0; i < VisualTreeHelper.GetChildrenCount(element); i++)
                Tree(VisualTreeHelper.GetChild(element, i), where);
        }
        var dictionaries = new[] { resources }.Concat(resources.MergedDictionaries);
        foreach (var dictionary in dictionaries)
            foreach (var key in dictionary.Keys) {
                object value = dictionary[key];
                string name = key is Type type ? type.Name : key.ToString() ?? "";
                Brush(value, name);
                if (value is not Style style)
                    continue;
                Setters(style.Setters, name);
                foreach (var trigger in style.Triggers.OfType<TriggerBase>())
                    Setters(trigger is Trigger t ? t.Setters : trigger is DataTrigger d ? d.Setters : new SetterBaseCollection(), name);
                if (style.Setters.OfType<Setter>().FirstOrDefault(s => s.Property == Control.TemplateProperty)?.Value
                        is not ControlTemplate template || !typeof(Control).IsAssignableFrom(style.TargetType) ||
                    style.TargetType.IsAbstract || style.TargetType.GetConstructor(Type.EmptyTypes) == null)
                    continue;
                foreach (var trigger in template.Triggers.OfType<Trigger>())
                    Setters(trigger.Setters, name + " template");
                var control = (Control)Activator.CreateInstance(style.TargetType)!;
                control.Style = style;
                control.ApplyTemplate();
                Tree(control, name);
            }
        check(stray.Count == 0, "Theme colours outside the palette: " + string.Join("; ", stray.Distinct().Take(8)));
    }
}
