#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BAC20
// Address: 0x1bac20 - 0x1badf0
void sub_001BAC20_0x1bac20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BAC20_0x1bac20");
#endif

    switch (ctx->pc) {
        case 0x1bad10u: goto label_1bad10;
        case 0x1bad94u: goto label_1bad94;
        case 0x1bad9cu: goto label_1bad9c;
        case 0x1bada4u: goto label_1bada4;
        case 0x1badacu: goto label_1badac;
        case 0x1badc0u: goto label_1badc0;
        case 0x1badccu: goto label_1badcc;
        case 0x1badd8u: goto label_1badd8;
        case 0x1bade4u: goto label_1bade4;
        default: break;
    }

    ctx->pc = 0x1bac20u;

    // 0x1bac20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bac20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bac24: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac28: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bac28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bac2c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bac2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bac30: 0xa0204475  sb          $zero, 0x4475($at)
    ctx->pc = 0x1bac30u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17525), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bac34: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac38: 0xa02043c7  sb          $zero, 0x43C7($at)
    ctx->pc = 0x1bac38u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17351), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bac3c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac40: 0xa02243cf  sb          $v0, 0x43CF($at)
    ctx->pc = 0x1bac40u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17359), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac48: 0xa02243cc  sb          $v0, 0x43CC($at)
    ctx->pc = 0x1bac48u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17356), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac4c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac50: 0xa02243c3  sb          $v0, 0x43C3($at)
    ctx->pc = 0x1bac50u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17347), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac54: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac58: 0xa02243c4  sb          $v0, 0x43C4($at)
    ctx->pc = 0x1bac58u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17348), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac5c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac60: 0xa02043c8  sb          $zero, 0x43C8($at)
    ctx->pc = 0x1bac60u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17352), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bac64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac68: 0xa02243c2  sb          $v0, 0x43C2($at)
    ctx->pc = 0x1bac68u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17346), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac6c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac70: 0xa02043c1  sb          $zero, 0x43C1($at)
    ctx->pc = 0x1bac70u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17345), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bac74: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac78: 0xa02243c6  sb          $v0, 0x43C6($at)
    ctx->pc = 0x1bac78u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17350), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac7c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac80: 0xa02243fd  sb          $v0, 0x43FD($at)
    ctx->pc = 0x1bac80u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17405), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac84: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac88: 0xa02243cb  sb          $v0, 0x43CB($at)
    ctx->pc = 0x1bac88u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17355), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bac8c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac90: 0x802741a0  lb          $a3, 0x41A0($at)
    ctx->pc = 0x1bac90u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16800)));
    // 0x1bac94: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bac98: 0x802641a1  lb          $a2, 0x41A1($at)
    ctx->pc = 0x1bac98u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16801)));
    // 0x1bac9c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bac9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baca0: 0x802541a2  lb          $a1, 0x41A2($at)
    ctx->pc = 0x1baca0u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16802)));
    // 0x1baca4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1baca4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baca8: 0x802441a3  lb          $a0, 0x41A3($at)
    ctx->pc = 0x1baca8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16803)));
    // 0x1bacac: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacb0: 0x802341a4  lb          $v1, 0x41A4($at)
    ctx->pc = 0x1bacb0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16804)));
    // 0x1bacb4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacb8: 0x802241a6  lb          $v0, 0x41A6($at)
    ctx->pc = 0x1bacb8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16806)));
    // 0x1bacbc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacc0: 0xa02743c5  sb          $a3, 0x43C5($at)
    ctx->pc = 0x1bacc0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17349), (uint8_t)GPR_U32(ctx, 7));
    // 0x1bacc4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacc8: 0xa02643c9  sb          $a2, 0x43C9($at)
    ctx->pc = 0x1bacc8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17353), (uint8_t)GPR_U32(ctx, 6));
    // 0x1baccc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacd0: 0xa02543ca  sb          $a1, 0x43CA($at)
    ctx->pc = 0x1bacd0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17354), (uint8_t)GPR_U32(ctx, 5));
    // 0x1bacd4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacd8: 0xa02443ec  sb          $a0, 0x43EC($at)
    ctx->pc = 0x1bacd8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17388), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bacdc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bace0: 0xa02343ef  sb          $v1, 0x43EF($at)
    ctx->pc = 0x1bace0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17391), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bace4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bace4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bace8: 0xa02243ed  sb          $v0, 0x43ED($at)
    ctx->pc = 0x1bace8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17389), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bacec: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacf0: 0x802341a7  lb          $v1, 0x41A7($at)
    ctx->pc = 0x1bacf0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16807)));
    // 0x1bacf4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bacf8: 0x802241a5  lb          $v0, 0x41A5($at)
    ctx->pc = 0x1bacf8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16805)));
    // 0x1bacfc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bacfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad00: 0xa02343ee  sb          $v1, 0x43EE($at)
    ctx->pc = 0x1bad00u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17390), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bad04: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad08: 0xc06bb90  jal         func_1AEE40
    ctx->pc = 0x1BAD08u;
    SET_GPR_U32(ctx, 31, 0x1BAD10u);
    ctx->pc = 0x1BAD0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAD08u;
            // 0x1bad0c: 0xa02243f0  sb          $v0, 0x43F0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17392), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEE40u;
    if (runtime->hasFunction(0x1AEE40u)) {
        auto targetFn = runtime->lookupFunction(0x1AEE40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAD10u; }
        if (ctx->pc != 0x1BAD10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEE40_0x1aee40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAD10u; }
        if (ctx->pc != 0x1BAD10u) { return; }
    }
    ctx->pc = 0x1BAD10u;
label_1bad10:
    // 0x1bad10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad14: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1bad14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1bad18: 0xa02043f2  sb          $zero, 0x43F2($at)
    ctx->pc = 0x1bad18u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17394), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bad1c: 0x2404001b  addiu       $a0, $zero, 0x1B
    ctx->pc = 0x1bad1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x1bad20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad24: 0xa42243da  sh          $v0, 0x43DA($at)
    ctx->pc = 0x1bad24u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17370), (uint16_t)GPR_U32(ctx, 2));
    // 0x1bad28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad2c: 0xa02043d8  sb          $zero, 0x43D8($at)
    ctx->pc = 0x1bad2cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17368), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bad30: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad34: 0xa02043d9  sb          $zero, 0x43D9($at)
    ctx->pc = 0x1bad34u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17369), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bad38: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad3c: 0xa42043dc  sh          $zero, 0x43DC($at)
    ctx->pc = 0x1bad3cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17372), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bad40: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad44: 0xa42043de  sh          $zero, 0x43DE($at)
    ctx->pc = 0x1bad44u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17374), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bad48: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad4c: 0xa42043e0  sh          $zero, 0x43E0($at)
    ctx->pc = 0x1bad4cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17376), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bad50: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad54: 0xa42043e2  sh          $zero, 0x43E2($at)
    ctx->pc = 0x1bad54u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17378), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bad58: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad5c: 0xa42043e4  sh          $zero, 0x43E4($at)
    ctx->pc = 0x1bad5cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17380), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bad60: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad64: 0xa42043e6  sh          $zero, 0x43E6($at)
    ctx->pc = 0x1bad64u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17382), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bad68: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad6c: 0xa02043e8  sb          $zero, 0x43E8($at)
    ctx->pc = 0x1bad6cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17384), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bad70: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad74: 0xa02043e9  sb          $zero, 0x43E9($at)
    ctx->pc = 0x1bad74u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17385), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bad78: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad7c: 0xa02043ea  sb          $zero, 0x43EA($at)
    ctx->pc = 0x1bad7cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17386), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bad80: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad84: 0xa02043fa  sb          $zero, 0x43FA($at)
    ctx->pc = 0x1bad84u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17402), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bad88: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bad88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bad8c: 0xc06e0ac  jal         func_1B82B0
    ctx->pc = 0x1BAD8Cu;
    SET_GPR_U32(ctx, 31, 0x1BAD94u);
    ctx->pc = 0x1BAD90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAD8Cu;
            // 0x1bad90: 0xa02043fb  sb          $zero, 0x43FB($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17403), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82B0u;
    if (runtime->hasFunction(0x1B82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAD94u; }
        if (ctx->pc != 0x1BAD94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82B0_0x1b82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAD94u; }
        if (ctx->pc != 0x1BAD94u) { return; }
    }
    ctx->pc = 0x1BAD94u;
label_1bad94:
    // 0x1bad94: 0xc06e0ac  jal         func_1B82B0
    ctx->pc = 0x1BAD94u;
    SET_GPR_U32(ctx, 31, 0x1BAD9Cu);
    ctx->pc = 0x1BAD98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAD94u;
            // 0x1bad98: 0x24040050  addiu       $a0, $zero, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82B0u;
    if (runtime->hasFunction(0x1B82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAD9Cu; }
        if (ctx->pc != 0x1BAD9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82B0_0x1b82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAD9Cu; }
        if (ctx->pc != 0x1BAD9Cu) { return; }
    }
    ctx->pc = 0x1BAD9Cu;
label_1bad9c:
    // 0x1bad9c: 0xc06e0ac  jal         func_1B82B0
    ctx->pc = 0x1BAD9Cu;
    SET_GPR_U32(ctx, 31, 0x1BADA4u);
    ctx->pc = 0x1BADA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAD9Cu;
            // 0x1bada0: 0x24040051  addiu       $a0, $zero, 0x51 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 81));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82B0u;
    if (runtime->hasFunction(0x1B82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADA4u; }
        if (ctx->pc != 0x1BADA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82B0_0x1b82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADA4u; }
        if (ctx->pc != 0x1BADA4u) { return; }
    }
    ctx->pc = 0x1BADA4u;
label_1bada4:
    // 0x1bada4: 0xc06e0ac  jal         func_1B82B0
    ctx->pc = 0x1BADA4u;
    SET_GPR_U32(ctx, 31, 0x1BADACu);
    ctx->pc = 0x1BADA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BADA4u;
            // 0x1bada8: 0x24040054  addiu       $a0, $zero, 0x54 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 84));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82B0u;
    if (runtime->hasFunction(0x1B82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADACu; }
        if (ctx->pc != 0x1BADACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82B0_0x1b82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADACu; }
        if (ctx->pc != 0x1BADACu) { return; }
    }
    ctx->pc = 0x1BADACu;
label_1badac:
    // 0x1badac: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1badacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1badb0: 0x802443ed  lb          $a0, 0x43ED($at)
    ctx->pc = 0x1badb0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17389)));
    // 0x1badb4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1badb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1badb8: 0xc06bde4  jal         func_1AF790
    ctx->pc = 0x1BADB8u;
    SET_GPR_U32(ctx, 31, 0x1BADC0u);
    ctx->pc = 0x1BADBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BADB8u;
            // 0x1badbc: 0x802543ee  lb          $a1, 0x43EE($at) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17390)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF790u;
    if (runtime->hasFunction(0x1AF790u)) {
        auto targetFn = runtime->lookupFunction(0x1AF790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADC0u; }
        if (ctx->pc != 0x1BADC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF790_0x1af790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADC0u; }
        if (ctx->pc != 0x1BADC0u) { return; }
    }
    ctx->pc = 0x1BADC0u;
label_1badc0:
    // 0x1badc0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1badc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1badc4: 0xc06e1b0  jal         func_1B86C0
    ctx->pc = 0x1BADC4u;
    SET_GPR_U32(ctx, 31, 0x1BADCCu);
    ctx->pc = 0x1BADC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BADC4u;
            // 0x1badc8: 0x902443c5  lbu         $a0, 0x43C5($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17349)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B86C0u;
    if (runtime->hasFunction(0x1B86C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B86C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADCCu; }
        if (ctx->pc != 0x1BADCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B86C0_0x1b86c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADCCu; }
        if (ctx->pc != 0x1BADCCu) { return; }
    }
    ctx->pc = 0x1BADCCu;
label_1badcc:
    // 0x1badcc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1badccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1badd0: 0xc06e1bc  jal         func_1B86F0
    ctx->pc = 0x1BADD0u;
    SET_GPR_U32(ctx, 31, 0x1BADD8u);
    ctx->pc = 0x1BADD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BADD0u;
            // 0x1badd4: 0x902443ca  lbu         $a0, 0x43CA($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17354)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B86F0u;
    if (runtime->hasFunction(0x1B86F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B86F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADD8u; }
        if (ctx->pc != 0x1BADD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B86F0_0x1b86f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADD8u; }
        if (ctx->pc != 0x1BADD8u) { return; }
    }
    ctx->pc = 0x1BADD8u;
label_1badd8:
    // 0x1badd8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1badd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baddc: 0xc06e1e0  jal         func_1B8780
    ctx->pc = 0x1BADDCu;
    SET_GPR_U32(ctx, 31, 0x1BADE4u);
    ctx->pc = 0x1BADE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BADDCu;
            // 0x1bade0: 0x902443c9  lbu         $a0, 0x43C9($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17353)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8780u;
    if (runtime->hasFunction(0x1B8780u)) {
        auto targetFn = runtime->lookupFunction(0x1B8780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADE4u; }
        if (ctx->pc != 0x1BADE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8780_0x1b8780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BADE4u; }
        if (ctx->pc != 0x1BADE4u) { return; }
    }
    ctx->pc = 0x1BADE4u;
label_1bade4:
    // 0x1bade4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bade4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bade8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BADE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BADECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BADE8u;
            // 0x1badec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BAD10u: goto label_1bad10;
            case 0x1BAD94u: goto label_1bad94;
            case 0x1BAD9Cu: goto label_1bad9c;
            case 0x1BADA4u: goto label_1bada4;
            case 0x1BADACu: goto label_1badac;
            case 0x1BADC0u: goto label_1badc0;
            case 0x1BADCCu: goto label_1badcc;
            case 0x1BADD8u: goto label_1badd8;
            case 0x1BADE4u: goto label_1bade4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BADF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
