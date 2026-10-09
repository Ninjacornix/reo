#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1260
// Address: 0x1b1260 - 0x1b12c0
void sub_001B1260_0x1b1260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1260_0x1b1260");
#endif

    ctx->pc = 0x1b1260u;

    // 0x1b1260: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1260u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b1264: 0x8422dd80  lh          $v0, -0x2280($at)
    ctx->pc = 0x1b1264u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294958464)));
    // 0x1b1268: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B1268u;
    {
        const bool branch_taken_0x1b1268 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B126Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1268u;
            // 0x1b126c: 0x3c01004f  lui         $at, 0x4F (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1268) {
            ctx->pc = 0x1B1278u;
            goto label_1b1278;
        }
    }
    ctx->pc = 0x1B1270u;
    // 0x1b1270: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1B1270u;
    {
        const bool branch_taken_0x1b1270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1270u;
            // 0x1b1274: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1270) {
            ctx->pc = 0x1B12ACu;
            goto label_1b12ac;
        }
    }
    ctx->pc = 0x1B1278u;
label_1b1278:
    // 0x1b1278: 0x8c23cb70  lw          $v1, -0x3490($at)
    ctx->pc = 0x1b1278u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294953840)));
    // 0x1b127c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1b127cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b1280: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1280u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b1284: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1b1284u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1b1288: 0x8c24cb70  lw          $a0, -0x3490($at)
    ctx->pc = 0x1b1288u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294953840)));
    // 0x1b128c: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b128cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b1290: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1b1290u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1b1294: 0x8423dd80  lh          $v1, -0x2280($at)
    ctx->pc = 0x1b1294u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294958464)));
    // 0x1b1298: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1298u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b129c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b129cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b12a0: 0xac24cb70  sw          $a0, -0x3490($at)
    ctx->pc = 0x1b12a0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294953840), GPR_U32(ctx, 4));
    // 0x1b12a4: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b12a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b12a8: 0xa423dd80  sh          $v1, -0x2280($at)
    ctx->pc = 0x1b12a8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294958464), (uint16_t)GPR_U32(ctx, 3));
label_1b12ac:
    // 0x1b12ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1B12ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1278u: goto label_1b1278;
            case 0x1B12ACu: goto label_1b12ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B12B4u;
    // 0x1b12b4: 0x0  nop
    ctx->pc = 0x1b12b4u;
    // NOP
    // 0x1b12b8: 0x0  nop
    ctx->pc = 0x1b12b8u;
    // NOP
    // 0x1b12bc: 0x0  nop
    ctx->pc = 0x1b12bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
