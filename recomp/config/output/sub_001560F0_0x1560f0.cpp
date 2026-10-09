#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001560F0
// Address: 0x1560f0 - 0x1562d0
void sub_001560F0_0x1560f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001560F0_0x1560f0");
#endif

    switch (ctx->pc) {
        case 0x156100u: goto label_156100;
        case 0x156128u: goto label_156128;
        case 0x156218u: goto label_156218;
        case 0x156240u: goto label_156240;
        default: break;
    }

    ctx->pc = 0x1560f0u;

    // 0x1560f0: 0x30c3000f  andi        $v1, $a2, 0xF
    ctx->pc = 0x1560f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x1560f4: 0x5060000a  beql        $v1, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x1560F4u;
    {
        const bool branch_taken_0x1560f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1560f4) {
            ctx->pc = 0x1560F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1560F4u;
            // 0x1560f8: 0x63102  srl         $a2, $a2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x156120u;
            goto label_156120;
        }
    }
    ctx->pc = 0x1560FCu;
    // 0x1560fc: 0x0  nop
    ctx->pc = 0x1560fcu;
    // NOP
label_156100:
    // 0x156100: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x156100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156104: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156104u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156108: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x156108u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x15610c: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x15610cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x156110: 0x0  nop
    ctx->pc = 0x156110u;
    // NOP
    // 0x156114: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x156114u;
    {
        const bool branch_taken_0x156114 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x156118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156114u;
            // 0x156118: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156114) {
            ctx->pc = 0x156100u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156100;
        }
    }
    ctx->pc = 0x15611Cu;
    // 0x15611c: 0x63102  srl         $a2, $a2, 4
    ctx->pc = 0x15611cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
label_156120:
    // 0x156120: 0x10c00034  beqz        $a2, . + 4 + (0x34 << 2)
    ctx->pc = 0x156120u;
    {
        const bool branch_taken_0x156120 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x156120) {
            ctx->pc = 0x1561F4u;
            goto label_1561f4;
        }
    }
    ctx->pc = 0x156128u;
label_156128:
    // 0x156128: 0x8ca80000  lw          $t0, 0x0($a1)
    ctx->pc = 0x156128u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15612c: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x15612cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156130: 0x8ca70000  lw          $a3, 0x0($a1)
    ctx->pc = 0x156130u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156134: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156134u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156138: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x156138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15613c: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x15613cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156140: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x156140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156144: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156144u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156148: 0xac880000  sw          $t0, 0x0($a0)
    ctx->pc = 0x156148u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 8));
    // 0x15614c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x15614cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x156150: 0xac870004  sw          $a3, 0x4($a0)
    ctx->pc = 0x156150u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 7));
    // 0x156154: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x156154u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x156158: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x156158u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x15615c: 0x8ca80000  lw          $t0, 0x0($a1)
    ctx->pc = 0x15615cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156160: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156160u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156164: 0x8ca70000  lw          $a3, 0x0($a1)
    ctx->pc = 0x156164u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156168: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156168u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x15616c: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x15616cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156170: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156170u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156174: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x156174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156178: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156178u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x15617c: 0xac880010  sw          $t0, 0x10($a0)
    ctx->pc = 0x15617cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 8));
    // 0x156180: 0xac870014  sw          $a3, 0x14($a0)
    ctx->pc = 0x156180u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 7));
    // 0x156184: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x156184u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x156188: 0xac82001c  sw          $v0, 0x1C($a0)
    ctx->pc = 0x156188u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
    // 0x15618c: 0x8ca80000  lw          $t0, 0x0($a1)
    ctx->pc = 0x15618cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156190: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156190u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x156194: 0x8ca70000  lw          $a3, 0x0($a1)
    ctx->pc = 0x156194u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x156198: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x156198u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x15619c: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x15619cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1561a0: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1561a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1561a4: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1561a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1561a8: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1561a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1561ac: 0xac880020  sw          $t0, 0x20($a0)
    ctx->pc = 0x1561acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 8));
    // 0x1561b0: 0xac870024  sw          $a3, 0x24($a0)
    ctx->pc = 0x1561b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 7));
    // 0x1561b4: 0xac830028  sw          $v1, 0x28($a0)
    ctx->pc = 0x1561b4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 3));
    // 0x1561b8: 0xac82002c  sw          $v0, 0x2C($a0)
    ctx->pc = 0x1561b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 2));
    // 0x1561bc: 0x8ca80000  lw          $t0, 0x0($a1)
    ctx->pc = 0x1561bcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1561c0: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1561c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1561c4: 0x8ca70000  lw          $a3, 0x0($a1)
    ctx->pc = 0x1561c4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1561c8: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1561c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1561cc: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1561ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1561d0: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1561d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1561d4: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1561d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1561d8: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1561d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1561dc: 0xac880030  sw          $t0, 0x30($a0)
    ctx->pc = 0x1561dcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 8));
    // 0x1561e0: 0xac870034  sw          $a3, 0x34($a0)
    ctx->pc = 0x1561e0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 7));
    // 0x1561e4: 0xac830038  sw          $v1, 0x38($a0)
    ctx->pc = 0x1561e4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 3));
    // 0x1561e8: 0xac82003c  sw          $v0, 0x3C($a0)
    ctx->pc = 0x1561e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 2));
    // 0x1561ec: 0x14c0ffce  bnez        $a2, . + 4 + (-0x32 << 2)
    ctx->pc = 0x1561ECu;
    {
        const bool branch_taken_0x1561ec = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1561F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1561ECu;
            // 0x1561f0: 0x24840040  addiu       $a0, $a0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1561ec) {
            ctx->pc = 0x156128u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156128;
        }
    }
    ctx->pc = 0x1561F4u;
label_1561f4:
    // 0x1561f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1561F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x156100u: goto label_156100;
            case 0x156120u: goto label_156120;
            case 0x156128u: goto label_156128;
            case 0x1561F4u: goto label_1561f4;
            case 0x156218u: goto label_156218;
            case 0x156234u: goto label_156234;
            case 0x156240u: goto label_156240;
            case 0x1562C8u: goto label_1562c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1561FCu;
    // 0x1561fc: 0x0  nop
    ctx->pc = 0x1561fcu;
    // NOP
    // 0x156200: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x156200u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x156204: 0x30c2000f  andi        $v0, $a2, 0xF
    ctx->pc = 0x156204u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x156208: 0x52e03  sra         $a1, $a1, 24
    ctx->pc = 0x156208u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x15620c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15620Cu;
    {
        const bool branch_taken_0x15620c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x156210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15620Cu;
            // 0x156210: 0x862021  addu        $a0, $a0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15620c) {
            ctx->pc = 0x156234u;
            goto label_156234;
        }
    }
    ctx->pc = 0x156214u;
    // 0x156214: 0x0  nop
    ctx->pc = 0x156214u;
    // NOP
label_156218:
    // 0x156218: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156218u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x15621c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x15621cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x156220: 0x0  nop
    ctx->pc = 0x156220u;
    // NOP
    // 0x156224: 0x0  nop
    ctx->pc = 0x156224u;
    // NOP
    // 0x156228: 0x0  nop
    ctx->pc = 0x156228u;
    // NOP
    // 0x15622c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x15622Cu;
    {
        const bool branch_taken_0x15622c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x156230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15622Cu;
            // 0x156230: 0xa0850000  sb          $a1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15622c) {
            ctx->pc = 0x156218u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156218;
        }
    }
    ctx->pc = 0x156234u;
label_156234:
    // 0x156234: 0x63102  srl         $a2, $a2, 4
    ctx->pc = 0x156234u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x156238: 0x10c00023  beqz        $a2, . + 4 + (0x23 << 2)
    ctx->pc = 0x156238u;
    {
        const bool branch_taken_0x156238 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x156238) {
            ctx->pc = 0x1562C8u;
            goto label_1562c8;
        }
    }
    ctx->pc = 0x156240u;
label_156240:
    // 0x156240: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156240u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156244: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x156244u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x156248: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156248u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15624c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15624cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156250: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156250u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156254: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156254u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156258: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156258u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15625c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15625cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156260: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156260u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156264: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156264u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156268: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156268u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15626c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15626cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156270: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156270u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156274: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156274u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156278: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156278u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15627c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15627cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156280: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156280u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156284: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156288: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156288u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15628c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15628cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156290: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156290u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x156294: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x156294u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x156298: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x156298u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x15629c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15629cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562a0: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562a0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562a4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562a8: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562a8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562ac: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562b0: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562b0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562b4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562b8: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1562b8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1562bc: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1562bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1562c0: 0x14c0ffdf  bnez        $a2, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1562C0u;
    {
        const bool branch_taken_0x1562c0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1562C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1562C0u;
            // 0x1562c4: 0xa0850000  sb          $a1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1562c0) {
            ctx->pc = 0x156240u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156240;
        }
    }
    ctx->pc = 0x1562C8u;
label_1562c8:
    // 0x1562c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1562C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x156100u: goto label_156100;
            case 0x156120u: goto label_156120;
            case 0x156128u: goto label_156128;
            case 0x1561F4u: goto label_1561f4;
            case 0x156218u: goto label_156218;
            case 0x156234u: goto label_156234;
            case 0x156240u: goto label_156240;
            case 0x1562C8u: goto label_1562c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1562D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
