#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1820
// Address: 0x1a1820 - 0x1a1890
void sub_001A1820_0x1a1820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1820_0x1a1820");
#endif

    switch (ctx->pc) {
        case 0x1a1840u: goto label_1a1840;
        case 0x1a186cu: goto label_1a186c;
        default: break;
    }

    ctx->pc = 0x1a1820u;

    // 0x1a1820: 0x30a70003  andi        $a3, $a1, 0x3
    ctx->pc = 0x1a1820u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)3);
    // 0x1a1824: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1a1824u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1828: 0x4a10008  bgez        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A1828u;
    {
        const bool branch_taken_0x1a1828 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x1A182Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1828u;
            // 0x1a182c: 0x53083  sra         $a2, $a1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1828) {
            ctx->pc = 0x1A184Cu;
            goto label_1a184c;
        }
    }
    ctx->pc = 0x1A1830u;
    // 0x1a1830: 0x24a30003  addiu       $v1, $a1, 0x3
    ctx->pc = 0x1a1830u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
    // 0x1a1834: 0x33083  sra         $a2, $v1, 2
    ctx->pc = 0x1a1834u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 3), 2));
    // 0x1a1838: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A1838u;
    {
        const bool branch_taken_0x1a1838 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A183Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1838u;
            // 0x1a183c: 0x106182a  slt         $v1, $t0, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1838) {
            ctx->pc = 0x1A1850u;
            goto label_1a1850;
        }
    }
    ctx->pc = 0x1A1840u;
label_1a1840:
    // 0x1a1840: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1a1840u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1a1844: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1a1844u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1a1848: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1a1848u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
label_1a184c:
    // 0x1a184c: 0x106182a  slt         $v1, $t0, $a2
    ctx->pc = 0x1a184cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
label_1a1850:
    // 0x1a1850: 0x0  nop
    ctx->pc = 0x1a1850u;
    // NOP
    // 0x1a1854: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A1854u;
    {
        const bool branch_taken_0x1a1854 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a1854) {
            ctx->pc = 0x1A1840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a1840;
        }
    }
    ctx->pc = 0x1A185Cu;
    // 0x1a185c: 0x10e0000a  beqz        $a3, . + 4 + (0xA << 2)
    ctx->pc = 0x1A185Cu;
    {
        const bool branch_taken_0x1a185c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a185c) {
            ctx->pc = 0x1A1888u;
            goto label_1a1888;
        }
    }
    ctx->pc = 0x1A1864u;
    // 0x1a1864: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A1864u;
    {
        const bool branch_taken_0x1a1864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1864u;
            // 0x1a1868: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1864) {
            ctx->pc = 0x1A1878u;
            goto label_1a1878;
        }
    }
    ctx->pc = 0x1A186Cu;
label_1a186c:
    // 0x1a186c: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1a186cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a1870: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1a1870u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1a1874: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a1874u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1a1878:
    // 0x1a1878: 0xa7182a  slt         $v1, $a1, $a3
    ctx->pc = 0x1a1878u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1a187c: 0x0  nop
    ctx->pc = 0x1a187cu;
    // NOP
    // 0x1a1880: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A1880u;
    {
        const bool branch_taken_0x1a1880 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a1880) {
            ctx->pc = 0x1A186Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a186c;
        }
    }
    ctx->pc = 0x1A1888u;
label_1a1888:
    // 0x1a1888: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1840u: goto label_1a1840;
            case 0x1A184Cu: goto label_1a184c;
            case 0x1A1850u: goto label_1a1850;
            case 0x1A186Cu: goto label_1a186c;
            case 0x1A1878u: goto label_1a1878;
            case 0x1A1888u: goto label_1a1888;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1890u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
