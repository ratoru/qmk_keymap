# Custom QMK Keymaps

These are my keymaps for the [Kyria rev3](https://github.com/splitkb/kyria) and the [Aurora Sweep](https://splitkb.com/collections/keyboard-kits/products/aurora-sweep).

It was heavily inspired by [Pascal Getreuer's keymap](https://github.com/getreuer/qmk-keymap). It uses a `Colemak-DH` base layer with an option to switch to `Qwerty`. I spent a lot of time trying to design a very efficient symbol layer for programming. To do so, I referred heavily to character and bigram frequencies in programming langues.

The keymap is compiled using a GitHub Action. I changed the target to `-e CONVERT_TO=liatris` in the GitHub Action since adding it in `rules.mk` did not work for me. If you have a [different controller](https://docs.qmk.fm/#/feature_converters?id=converters), you might want to remove this part in `build.yml`.

## Features

- [Caps Word](https://docs.qmk.fm/#/feature_caps_word)
- [Dynamic Macros](https://docs.qmk.fm/#/feature_dynamic_macros)
- [Word Selection](https://getreuer.info/posts/keyboards/select-word/index.html) macro
- [Swapper](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum#swapper). Sends `cmd-key`, but holds `cmd` between consecutive keypresses.
- [Layer Lock](https://getreuer.info/posts/keyboards/layer-lock/index.html) macro
- `../` key in symbol layer
- Layer keys activated by the thumbs via mod-tap.
- Unused: [Repeat Key](https://docs.qmk.fm/#/feature_repeat_key)
- TBD: Home row mods?
- TBD: RGB lighting (= underglow) using `_noeeprom` functions.

## Kyria keymap

The number of each layer does not have much real relvancy, but let's you know which key switches to which layer. These layers are still in the early stages of development.

### `Colemak-DH` base layer (0)

![colemak-base-layer](docs/colemak-dh-base-layer.png)

### Navigation layer (2) 

Adapted the [Extend Layer](https://dreymar.colemak.org/layers-extend.html) for MacOS.

![navigation layer](docs/navigation-layer.png)

### Symbol layer (3)

Optimized for coding including `0` and `1`.

![symbol layer](docs/symbol-layer.png)

### Numpad layer (4)

![numpad layer](docs/numpad-layer.png)

### Gaming layer (5)

Numbers and `qwerty` row. Command keys on the right side if needed.

![gaming layer](docs/gaming-layer.png)

### Alternate `Qwerty` layer (1)

Option to switch to `Qwerty`.

![qwerty base layer](docs/qwerty-layer.png)

