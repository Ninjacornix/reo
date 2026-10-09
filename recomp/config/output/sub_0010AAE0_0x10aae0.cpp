#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010AAE0
// Address: 0x10aae0 - 0x10abb8
void sub_0010AAE0_0x10aae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010AAE0_0x10aae0");
#endif

    switch (ctx->pc) {
        case 0x10ab30u: goto label_10ab30;
        default: break;
    }

    ctx->pc = 0x10aae0u;

    // 0x10aae0: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x10aae0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aae4: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x10aae4u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x10aae8: 0x10e00023  beqz        $a3, . + 4 + (0x23 << 2)
    ctx->pc = 0x10AAE8u;
    {
        const bool branch_taken_0x10aae8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AAECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AAE8u;
            // 0x10aaec: 0xa0482d  daddu       $t1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10aae8) {
            ctx->pc = 0x10AB78u;
            goto label_10ab78;
        }
    }
    ctx->pc = 0x10AAF0u;
    // 0x10aaf0: 0x81250000  lb          $a1, 0x0($t1)
    ctx->pc = 0x10aaf0u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x10aaf4: 0x24e60020  addiu       $a2, $a3, 0x20
    ctx->pc = 0x10aaf4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 32));
    // 0x10aaf8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10aaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10aafc: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x10aafcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x10ab00: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10ab00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10ab04: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10ab04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10ab08: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x10ab08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x10ab0c: 0x90637769  lbu         $v1, 0x7769($v1)
    ctx->pc = 0x10ab0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 30569)));
    // 0x10ab10: 0x24a40020  addiu       $a0, $a1, 0x20
    ctx->pc = 0x10ab10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x10ab14: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x10ab14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x10ab18: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x10ab18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x10ab1c: 0xe2300a  movz        $a2, $a3, $v0
    ctx->pc = 0x10ab1cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 7));
    // 0x10ab20: 0xa3200a  movz        $a0, $a1, $v1
    ctx->pc = 0x10ab20u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 5));
    // 0x10ab24: 0x54c40015  bnel        $a2, $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x10AB24u;
    {
        const bool branch_taken_0x10ab24 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        if (branch_taken_0x10ab24) {
            ctx->pc = 0x10AB28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10AB24u;
            // 0x10ab28: 0x91050000  lbu         $a1, 0x0($t0) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AB7Cu;
            goto label_10ab7c;
        }
    }
    ctx->pc = 0x10AB2Cu;
    // 0x10ab2c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x10ab2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
label_10ab30:
    // 0x10ab30: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x10ab30u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x10ab34: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x10ab34u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x10ab38: 0x10c0000f  beqz        $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x10AB38u;
    {
        const bool branch_taken_0x10ab38 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AB38u;
            // 0x10ab3c: 0x24c70020  addiu       $a3, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ab38) {
            ctx->pc = 0x10AB78u;
            goto label_10ab78;
        }
    }
    ctx->pc = 0x10AB40u;
    // 0x10ab40: 0x81250000  lb          $a1, 0x0($t1)
    ctx->pc = 0x10ab40u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x10ab44: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10ab44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10ab48: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x10ab48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x10ab4c: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10ab4cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10ab50: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10ab50u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10ab54: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x10ab54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x10ab58: 0x90637769  lbu         $v1, 0x7769($v1)
    ctx->pc = 0x10ab58u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 30569)));
    // 0x10ab5c: 0x24a40020  addiu       $a0, $a1, 0x20
    ctx->pc = 0x10ab5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x10ab60: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x10ab60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x10ab64: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x10ab64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x10ab68: 0xe2300b  movn        $a2, $a3, $v0
    ctx->pc = 0x10ab68u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 7));
    // 0x10ab6c: 0xa3200a  movz        $a0, $a1, $v1
    ctx->pc = 0x10ab6cu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 5));
    // 0x10ab70: 0x50c4ffef  beql        $a2, $a0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x10AB70u;
    {
        const bool branch_taken_0x10ab70 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 4));
        if (branch_taken_0x10ab70) {
            ctx->pc = 0x10AB74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10AB70u;
            // 0x10ab74: 0x25080001  addiu       $t0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AB30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ab30;
        }
    }
    ctx->pc = 0x10AB78u;
label_10ab78:
    // 0x10ab78: 0x91050000  lbu         $a1, 0x0($t0)
    ctx->pc = 0x10ab78u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
label_10ab7c:
    // 0x10ab7c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x10ab7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x10ab80: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x10ab80u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x10ab84: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x10ab84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x10ab88: 0x90847769  lbu         $a0, 0x7769($a0)
    ctx->pc = 0x10ab88u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30569)));
    // 0x10ab8c: 0x24a70020  addiu       $a3, $a1, 0x20
    ctx->pc = 0x10ab8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x10ab90: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10ab90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10ab94: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10ab94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10ab98: 0x90637769  lbu         $v1, 0x7769($v1)
    ctx->pc = 0x10ab98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 30569)));
    // 0x10ab9c: 0x24460020  addiu       $a2, $v0, 0x20
    ctx->pc = 0x10ab9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
    // 0x10aba0: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x10aba0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x10aba4: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x10aba4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x10aba8: 0xe4280b  movn        $a1, $a3, $a0
    ctx->pc = 0x10aba8u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x10abac: 0xc3100b  movn        $v0, $a2, $v1
    ctx->pc = 0x10abacu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x10abb0: 0x3e00008  jr          $ra
    ctx->pc = 0x10ABB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10ABB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ABB0u;
            // 0x10abb4: 0xa21023  subu        $v0, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10AB30u: goto label_10ab30;
            case 0x10AB78u: goto label_10ab78;
            case 0x10AB7Cu: goto label_10ab7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10ABB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
