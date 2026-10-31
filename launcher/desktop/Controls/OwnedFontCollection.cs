using Avalonia.Media;
using Avalonia.Media.Fonts;

namespace Outbreak.Launcher.Desktop.Controls;

internal sealed class OwnedFontCollection:FontCollectionBase {
    public override Uri Key{get;}=new("fonts:OutbreakOwned");
    internal OwnedFontCollection(string path) {
        using var stream=File.OpenRead(path);
        if(!TryAddGlyphTypeface(stream,out var glyph)||glyph.FamilyName!=GameFont.FamilyName)
            throw new IOException("The owned game font could not be loaded.");
    }
    internal static FontFamily Load(string path) {
        var collection=new OwnedFontCollection(path);
        FontManager.Current.AddFontCollection(collection);
        var family=new FontFamily("fonts:OutbreakOwned#"+GameFont.FamilyName);
        if(!FontManager.Current.TryGetGlyphTypeface(new Typeface(family),out var glyph)||glyph.FamilyName!=GameFont.FamilyName)
            throw new IOException("The Outbreak font collection did not resolve correctly.");
        return family;
    }
}
