#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0DB0
// Address: 0x1b0db0 - 0x1b0ff0
void sub_001B0DB0_0x1b0db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0DB0_0x1b0db0");
#endif

    switch (ctx->pc) {
        case 0x1b0eb4u: goto label_1b0eb4;
        case 0x1b0fc0u: goto label_1b0fc0;
        default: break;
    }

    ctx->pc = 0x1b0db0u;

    // 0x1b0db0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0db4: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1b0db4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1b0db8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0db8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b0dbc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0dbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0dc0: 0x8c284220  lw          $t0, 0x4220($at)
    ctx->pc = 0x1b0dc0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16928)));
    // 0x1b0dc4: 0x24844210  addiu       $a0, $a0, 0x4210
    ctx->pc = 0x1b0dc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16912));
    // 0x1b0dc8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0dc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0dcc: 0x8c27421c  lw          $a3, 0x421C($at)
    ctx->pc = 0x1b0dccu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16924)));
    // 0x1b0dd0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0dd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0dd4: 0x8c264218  lw          $a2, 0x4218($at)
    ctx->pc = 0x1b0dd4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16920)));
    // 0x1b0dd8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0dd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0ddc: 0x8c254308  lw          $a1, 0x4308($at)
    ctx->pc = 0x1b0ddcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17160)));
    // 0x1b0de0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0de0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0de4: 0x84234324  lh          $v1, 0x4324($at)
    ctx->pc = 0x1b0de4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17188)));
    // 0x1b0de8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0de8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0dec: 0x84224326  lh          $v0, 0x4326($at)
    ctx->pc = 0x1b0decu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17190)));
    // 0x1b0df0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0df0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0df4: 0xac284224  sw          $t0, 0x4224($at)
    ctx->pc = 0x1b0df4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16932), GPR_U32(ctx, 8));
    // 0x1b0df8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0df8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0dfc: 0xac274220  sw          $a3, 0x4220($at)
    ctx->pc = 0x1b0dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16928), GPR_U32(ctx, 7));
    // 0x1b0e00: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e04: 0xac26421c  sw          $a2, 0x421C($at)
    ctx->pc = 0x1b0e04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16924), GPR_U32(ctx, 6));
    // 0x1b0e08: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e0c: 0xac254218  sw          $a1, 0x4218($at)
    ctx->pc = 0x1b0e0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16920), GPR_U32(ctx, 5));
    // 0x1b0e10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e14: 0xa4234234  sh          $v1, 0x4234($at)
    ctx->pc = 0x1b0e14u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16948), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b0e18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e1c: 0xa4224236  sh          $v0, 0x4236($at)
    ctx->pc = 0x1b0e1cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16950), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0e20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e24: 0x8c2a421c  lw          $t2, 0x421C($at)
    ctx->pc = 0x1b0e24u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16924)));
    // 0x1b0e28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e2c: 0x1404827  not         $t1, $t2
    ctx->pc = 0x1b0e2cu;
    SET_GPR_U64(ctx, 9, ~(GPR_U64(ctx, 10) | GPR_U64(ctx, 0)));
    // 0x1b0e30: 0x8c284218  lw          $t0, 0x4218($at)
    ctx->pc = 0x1b0e30u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16920)));
    // 0x1b0e34: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e38: 0x1094824  and         $t1, $t0, $t1
    ctx->pc = 0x1b0e38u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 8) & GPR_U64(ctx, 9));
    // 0x1b0e3c: 0x8427432c  lh          $a3, 0x432C($at)
    ctx->pc = 0x1b0e3cu;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17196)));
    // 0x1b0e40: 0x1004027  not         $t0, $t0
    ctx->pc = 0x1b0e40u;
    SET_GPR_U64(ctx, 8, ~(GPR_U64(ctx, 8) | GPR_U64(ctx, 0)));
    // 0x1b0e44: 0x1484024  and         $t0, $t2, $t0
    ctx->pc = 0x1b0e44u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 10) & GPR_U64(ctx, 8));
    // 0x1b0e48: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e4c: 0x8426432e  lh          $a2, 0x432E($at)
    ctx->pc = 0x1b0e4cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17198)));
    // 0x1b0e50: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e54: 0x84254320  lh          $a1, 0x4320($at)
    ctx->pc = 0x1b0e54u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17184)));
    // 0x1b0e58: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e5c: 0x84234328  lh          $v1, 0x4328($at)
    ctx->pc = 0x1b0e5cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17192)));
    // 0x1b0e60: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e64: 0x84224322  lh          $v0, 0x4322($at)
    ctx->pc = 0x1b0e64u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17186)));
    // 0x1b0e68: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e6c: 0xac294210  sw          $t1, 0x4210($at)
    ctx->pc = 0x1b0e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16912), GPR_U32(ctx, 9));
    // 0x1b0e70: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e74: 0xac284214  sw          $t0, 0x4214($at)
    ctx->pc = 0x1b0e74u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16916), GPR_U32(ctx, 8));
    // 0x1b0e78: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e7c: 0xa427423c  sh          $a3, 0x423C($at)
    ctx->pc = 0x1b0e7cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16956), (uint16_t)GPR_U32(ctx, 7));
    // 0x1b0e80: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e84: 0xa426423e  sh          $a2, 0x423E($at)
    ctx->pc = 0x1b0e84u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16958), (uint16_t)GPR_U32(ctx, 6));
    // 0x1b0e88: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e8c: 0xa4254230  sh          $a1, 0x4230($at)
    ctx->pc = 0x1b0e8cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16944), (uint16_t)GPR_U32(ctx, 5));
    // 0x1b0e90: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e94: 0xa4234238  sh          $v1, 0x4238($at)
    ctx->pc = 0x1b0e94u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16952), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b0e98: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0e98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0e9c: 0xa4224232  sh          $v0, 0x4232($at)
    ctx->pc = 0x1b0e9cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16946), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0ea0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0ea0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0ea4: 0x8422432a  lh          $v0, 0x432A($at)
    ctx->pc = 0x1b0ea4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 17194)));
    // 0x1b0ea8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0ea8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0eac: 0xc06c260  jal         func_1B0980
    ctx->pc = 0x1B0EACu;
    SET_GPR_U32(ctx, 31, 0x1B0EB4u);
    ctx->pc = 0x1B0EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0EACu;
            // 0x1b0eb0: 0xa422423a  sh          $v0, 0x423A($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 16954), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0980u;
    if (runtime->hasFunction(0x1B0980u)) {
        auto targetFn = runtime->lookupFunction(0x1B0980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0EB4u; }
        if (ctx->pc != 0x1B0EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0980_0x1b0980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0EB4u; }
        if (ctx->pc != 0x1B0EB4u) { return; }
    }
    ctx->pc = 0x1B0EB4u;
label_1b0eb4:
    // 0x1b0eb4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0eb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0eb8: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1b0eb8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1b0ebc: 0x8c2d4210  lw          $t5, 0x4210($at)
    ctx->pc = 0x1b0ebcu;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16912)));
    // 0x1b0ec0: 0x3c0c000f  lui         $t4, 0xF
    ctx->pc = 0x1b0ec0u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)15 << 16));
    // 0x1b0ec4: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1b0ec4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1b0ec8: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1b0ec8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1b0ecc: 0x24c643c0  addiu       $a2, $a2, 0x43C0
    ctx->pc = 0x1b0eccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 17344));
    // 0x1b0ed0: 0x24a543c4  addiu       $a1, $a1, 0x43C4
    ctx->pc = 0x1b0ed0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17348));
    // 0x1b0ed4: 0x248443c8  addiu       $a0, $a0, 0x43C8
    ctx->pc = 0x1b0ed4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17352));
    // 0x1b0ed8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0ed8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0edc: 0x1ac3824  and         $a3, $t5, $t4
    ctx->pc = 0x1b0edcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 13) & GPR_U64(ctx, 12));
    // 0x1b0ee0: 0x8c2a4218  lw          $t2, 0x4218($at)
    ctx->pc = 0x1b0ee0u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16920)));
    // 0x1b0ee4: 0x75c02  srl         $t3, $a3, 16
    ctx->pc = 0x1b0ee4u;
    SET_GPR_S32(ctx, 11, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x1b0ee8: 0x1ab5825  or          $t3, $t5, $t3
    ctx->pc = 0x1b0ee8u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 13) | GPR_U64(ctx, 11));
    // 0x1b0eec: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0eecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0ef0: 0x14c3824  and         $a3, $t2, $t4
    ctx->pc = 0x1b0ef0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 10) & GPR_U64(ctx, 12));
    // 0x1b0ef4: 0x8c294228  lw          $t1, 0x4228($at)
    ctx->pc = 0x1b0ef4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16936)));
    // 0x1b0ef8: 0x73c02  srl         $a3, $a3, 16
    ctx->pc = 0x1b0ef8u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x1b0efc: 0x1473825  or          $a3, $t2, $a3
    ctx->pc = 0x1b0efcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 10) | GPR_U64(ctx, 7));
    // 0x1b0f00: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0f00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0f04: 0x902843ec  lbu         $t0, 0x43EC($at)
    ctx->pc = 0x1b0f04u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17388)));
    // 0x1b0f08: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0f08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0f0c: 0xac2b4210  sw          $t3, 0x4210($at)
    ctx->pc = 0x1b0f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16912), GPR_U32(ctx, 11));
    // 0x1b0f10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0f10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0f14: 0xac274218  sw          $a3, 0x4218($at)
    ctx->pc = 0x1b0f14u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16920), GPR_U32(ctx, 7));
    // 0x1b0f18: 0x12c3824  and         $a3, $t1, $t4
    ctx->pc = 0x1b0f18u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 9) & GPR_U64(ctx, 12));
    // 0x1b0f1c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0f1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0f20: 0x73c02  srl         $a3, $a3, 16
    ctx->pc = 0x1b0f20u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x1b0f24: 0x8c2a4210  lw          $t2, 0x4210($at)
    ctx->pc = 0x1b0f24u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16912)));
    // 0x1b0f28: 0x1274825  or          $t1, $t1, $a3
    ctx->pc = 0x1b0f28u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 7));
    // 0x1b0f2c: 0x83840  sll         $a3, $t0, 1
    ctx->pc = 0x1b0f2cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1b0f30: 0xe83821  addu        $a3, $a3, $t0
    ctx->pc = 0x1b0f30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x1b0f34: 0x74080  sll         $t0, $a3, 2
    ctx->pc = 0x1b0f34u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1b0f38: 0xc83821  addu        $a3, $a2, $t0
    ctx->pc = 0x1b0f38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1b0f3c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0f3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0f40: 0xa83021  addu        $a2, $a1, $t0
    ctx->pc = 0x1b0f40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x1b0f44: 0xac294228  sw          $t1, 0x4228($at)
    ctx->pc = 0x1b0f44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16936), GPR_U32(ctx, 9));
    // 0x1b0f48: 0x882821  addu        $a1, $a0, $t0
    ctx->pc = 0x1b0f48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
    // 0x1b0f4c: 0x8ce70000  lw          $a3, 0x0($a3)
    ctx->pc = 0x1b0f4cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b0f50: 0x31440100  andi        $a0, $t2, 0x100
    ctx->pc = 0x1b0f50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)256);
    // 0x1b0f54: 0x8cc60000  lw          $a2, 0x0($a2)
    ctx->pc = 0x1b0f54u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b0f58: 0x8ca50000  lw          $a1, 0x0($a1)
    ctx->pc = 0x1b0f58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1b0f5c: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0F5Cu;
    {
        const bool branch_taken_0x1b0f5c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0F5Cu;
            // 0x1b0f60: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0f5c) {
            ctx->pc = 0x1B0F68u;
            goto label_1b0f68;
        }
    }
    ctx->pc = 0x1B0F64u;
    // 0x1b0f64: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x1b0f64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
label_1b0f68:
    // 0x1b0f68: 0x31440010  andi        $a0, $t2, 0x10
    ctx->pc = 0x1b0f68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)16);
    // 0x1b0f6c: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0F6Cu;
    {
        const bool branch_taken_0x1b0f6c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0F6Cu;
            // 0x1b0f70: 0x31440020  andi        $a0, $t2, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)32);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0f6c) {
            ctx->pc = 0x1B0F78u;
            goto label_1b0f78;
        }
    }
    ctx->pc = 0x1B0F74u;
    // 0x1b0f74: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x1b0f74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
label_1b0f78:
    // 0x1b0f78: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0F78u;
    {
        const bool branch_taken_0x1b0f78 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b0f78) {
            ctx->pc = 0x1B0F84u;
            goto label_1b0f84;
        }
    }
    ctx->pc = 0x1B0F80u;
    // 0x1b0f80: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x1b0f80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
label_1b0f84:
    // 0x1b0f84: 0x2404fecf  addiu       $a0, $zero, -0x131
    ctx->pc = 0x1b0f84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966991));
    // 0x1b0f88: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b0f88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b0f8c: 0x1442024  and         $a0, $t2, $a0
    ctx->pc = 0x1b0f8cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & GPR_U64(ctx, 4));
    // 0x1b0f90: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1b0f90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1b0f94: 0xac23ae90  sw          $v1, -0x5170($at)
    ctx->pc = 0x1b0f94u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294946448), GPR_U32(ctx, 3));
    // 0x1b0f98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b0f98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0f9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0F9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0F9Cu;
            // 0x1b0fa0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0EB4u: goto label_1b0eb4;
            case 0x1B0F68u: goto label_1b0f68;
            case 0x1B0F78u: goto label_1b0f78;
            case 0x1B0F84u: goto label_1b0f84;
            case 0x1B0FC0u: goto label_1b0fc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0FA4u;
    // 0x1b0fa4: 0x0  nop
    ctx->pc = 0x1b0fa4u;
    // NOP
    // 0x1b0fa8: 0x0  nop
    ctx->pc = 0x1b0fa8u;
    // NOP
    // 0x1b0fac: 0x0  nop
    ctx->pc = 0x1b0facu;
    // NOP
    // 0x1b0fb0: 0x3c060057  lui         $a2, 0x57
    ctx->pc = 0x1b0fb0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)87 << 16));
    // 0x1b0fb4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b0fb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0fb8: 0x24c698d0  addiu       $a2, $a2, -0x6730
    ctx->pc = 0x1b0fb8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294940880));
    // 0x1b0fbc: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1b0fbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b0fc0:
    // 0x1b0fc0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b0fc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1b0fc4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1b0fc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1b0fc8: 0x28a302bc  slti        $v1, $a1, 0x2BC
    ctx->pc = 0x1b0fc8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)700) ? 1 : 0);
    // 0x1b0fcc: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1b0fccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1b0fd0: 0x0  nop
    ctx->pc = 0x1b0fd0u;
    // NOP
    // 0x1b0fd4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B0FD4u;
    {
        const bool branch_taken_0x1b0fd4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b0fd4) {
            ctx->pc = 0x1B0FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0fc0;
        }
    }
    ctx->pc = 0x1B0FDCu;
    // 0x1b0fdc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0FDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0EB4u: goto label_1b0eb4;
            case 0x1B0F68u: goto label_1b0f68;
            case 0x1B0F78u: goto label_1b0f78;
            case 0x1B0F84u: goto label_1b0f84;
            case 0x1B0FC0u: goto label_1b0fc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0FE4u;
    // 0x1b0fe4: 0x0  nop
    ctx->pc = 0x1b0fe4u;
    // NOP
    // 0x1b0fe8: 0x0  nop
    ctx->pc = 0x1b0fe8u;
    // NOP
    // 0x1b0fec: 0x0  nop
    ctx->pc = 0x1b0fecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
