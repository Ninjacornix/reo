"""Add per-game endpoint selection to a staged copy of raylib audio; never edit upstream."""
import argparse
from pathlib import Path


def instrument(source):
    source = source.replace("\r\n", "\n")
    replacements = (
        ("void InitAudioDevice(void)\n{", '#include "runtime/audio/reo_output_device.h"\nvoid InitAudioDevice(void)\n{'),
        ("config.playback.pDeviceID = NULL;  // NULL for the default playback AUDIO.System.device",
         "ma_device_id reoOutputId;\n    config.playback.pDeviceID = reoAudioOutputDevice(&AUDIO.System.context, &reoOutputId);"),
        ("result = ma_device_init(&AUDIO.System.context, &config, &AUDIO.System.device);",
         "result = reoAudioInitDevice(&AUDIO.System.context, &config, &AUDIO.System.device);"),
    )
    for original, replacement in replacements:
        if source.count(original) != 1:
            raise ValueError("The reviewed raylib audio initialization changed; output selection was not applied")
        source = source.replace(original, replacement)
    return "// REO: altered raylib source, adding per-game audio output selection.\n" + source


def prepare(source, target):
    source, target = Path(source), Path(target)
    contents = instrument(source.read_text(encoding="utf-8"))
    target.parent.mkdir(parents=True, exist_ok=True)
    if not target.exists() or target.read_text(encoding="utf-8") != contents:
        target.write_text(contents, encoding="utf-8")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("target", type=Path)
    args = parser.parse_args()
    prepare(args.source, args.target)
