#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A81E0
// Address: 0x1a81e0 - 0x1a82b0
void sub_001A81E0_0x1a81e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A81E0_0x1a81e0");
#endif

    switch (ctx->pc) {
        case 0x1a8214u: goto label_1a8214;
        case 0x1a825cu: goto label_1a825c;
        default: break;
    }

    ctx->pc = 0x1a81e0u;

    // 0x1a81e0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a81e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a81e4: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a81e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a81e8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1a81e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1a81ec: 0x28420200  slti        $v0, $v0, 0x200
    ctx->pc = 0x1a81ecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x1a81f0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A81F0u;
    {
        const bool branch_taken_0x1a81f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A81F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A81F0u;
            // 0x1a81f4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a81f0) {
            ctx->pc = 0x1A8200u;
            goto label_1a8200;
        }
    }
    ctx->pc = 0x1A81F8u;
    // 0x1a81f8: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1A81F8u;
    {
        const bool branch_taken_0x1a81f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a81f8) {
            ctx->pc = 0x1A82A8u;
            goto label_1a82a8;
        }
    }
    ctx->pc = 0x1A8200u;
label_1a8200:
    // 0x1a8200: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x1a8200u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a8204: 0x24080018  addiu       $t0, $zero, 0x18
    ctx->pc = 0x1a8204u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1a8208: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1a8208u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a820c: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a820cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a8210: 0x24630cc0  addiu       $v1, $v1, 0xCC0
    ctx->pc = 0x1a8210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3264));
label_1a8214:
    // 0x1a8214: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8214u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8218: 0x1062806  srlv        $a1, $a2, $t0
    ctx->pc = 0x1a8218u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 8) & 0x1F));
    // 0x1a821c: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a821cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8220: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x1a8220u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1a8224: 0x2508fff8  addiu       $t0, $t0, -0x8
    ctx->pc = 0x1a8224u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967288));
    // 0x1a8228: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a8228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a822c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a822cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8230: 0xa0450000  sb          $a1, 0x0($v0)
    ctx->pc = 0x1a8230u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a8234: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8238: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a8238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a823c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a823cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8240: 0x1ce0fff4  bgtz        $a3, . + 4 + (-0xC << 2)
    ctx->pc = 0x1A8240u;
    {
        const bool branch_taken_0x1a8240 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x1A8244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8240u;
            // 0x1a8244: 0xac220a60  sw          $v0, 0xA60($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8240) {
            ctx->pc = 0x1A8214u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a8214;
        }
    }
    ctx->pc = 0x1A8248u;
    // 0x1a8248: 0x8c870004  lw          $a3, 0x4($a0)
    ctx->pc = 0x1a8248u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a824c: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1a824cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a8250: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1a8250u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a8254: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1a8254u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1a8258: 0x24a50cc0  addiu       $a1, $a1, 0xCC0
    ctx->pc = 0x1a8258u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3264));
label_1a825c:
    // 0x1a825c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a825cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8260: 0xc71806  srlv        $v1, $a3, $a2
    ctx->pc = 0x1a8260u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 6) & 0x1F));
    // 0x1a8264: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8268: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1a8268u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1a826c: 0x24c6fff8  addiu       $a2, $a2, -0x8
    ctx->pc = 0x1a826cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967288));
    // 0x1a8270: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1a8270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1a8274: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8274u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8278: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1a8278u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a827c: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a827cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8280: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a8280u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a8284: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8284u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8288: 0x1c80fff4  bgtz        $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1A8288u;
    {
        const bool branch_taken_0x1a8288 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1A828Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8288u;
            // 0x1a828c: 0xac220a60  sw          $v0, 0xA60($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8288) {
            ctx->pc = 0x1A825Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a825c;
        }
    }
    ctx->pc = 0x1A8290u;
    // 0x1a8290: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8290u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8294: 0x240400ff  addiu       $a0, $zero, 0xFF
    ctx->pc = 0x1a8294u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a8298: 0x8c230a60  lw          $v1, 0xA60($at)
    ctx->pc = 0x1a8298u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a829c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a829cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a82a0: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1a82a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a82a4: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x1a82a4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
label_1a82a8:
    // 0x1a82a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A82A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A8200u: goto label_1a8200;
            case 0x1A8214u: goto label_1a8214;
            case 0x1A825Cu: goto label_1a825c;
            case 0x1A82A8u: goto label_1a82a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A82B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
